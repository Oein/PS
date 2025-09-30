#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Pos
{
  int x;
  int y;
};

enum Tile
{
  EMPTY,
  BLOCK,
  BOOSTER,
  TARGET,
  START
};

int h, w, booster;

vector<vector<Tile>> board;

Pos start, target;

using Status = pair<pair<int, int>, pair<int, int>>;
using QData = pair<int, Status>;

#define X(e) e.second.first.first
#define Y(e) e.second.first.second
#define Cost(e) e.first
#define Booster(e) e.second.second.first
#define Used(e) e.second.second.second

#include <filesystem>
namespace fs = std::filesystem;

// 현제 Status에 도달 했을때 cost, 이전 Status
map<Status, pair<int, Status>> visited;

char bstn[50][50] = {0};
int bstn_______ = 1;

#include <fstream>
#include <thread>

class FiledQ
{
  priority_queue<int, vector<int>, greater<int>> attrs;
  set<int> used;
  ull idx = 0;

public:
  void push(int cost, Status status)
  {
    if (used.find(cost) == used.end())
    {
      attrs.push(cost);
      used.insert(cost);
      fs::create_directories("./run/" + to_string(cost));
      cout << "Created directory for cost: " << cost << "\n";
    }

    // random file name
    string filename = "./run/" + to_string(cost) + "/" + to_string(idx) + ".txt";
    // open file
    ofstream file(filename);
    if (file.is_open())
    {
      // write status to file
      file << status.first.first << " ";
      file << status.first.second << " ";
      file << status.second.first << " ";
      file << status.second.second << "\n";
      file.close();
    }
  }

  int getCost()
  {
    if (attrs.empty())
      return -1; // No costs available
    return attrs.top();
  }

  vector<Status> get()
  {
    int cost = attrs.top();
    attrs.pop();

    vector<Status> statuses;

    fs::path dir = "./run/" + to_string(cost);
    ull size_ = 0;
    for (const auto &entry : fs::directory_iterator(dir))
    {
      size_++;
      if (entry.is_regular_file())
      {
        // ignore .DS_Store files
        if (entry.path().filename() == ".DS_Store")
          continue;
        ifstream file(entry.path());
        if (file.is_open())
        {
          Status status;
          file >> status.first.first >> status.first.second >> status.second.first >> status.second.second;
          statuses.push_back(status);
          file.close();
        }
      }
    }

    cout << "Read " << size_ << " statuses from directory: " << dir << "\n";

    // remove the directory after reading
    fs::remove_all(dir);

    return statuses;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> h >> w >> booster;
  cin.ignore();
  for (int i = 0; i < h; i++)
  {
    vector<Tile> line;

    string in_;
    getline(cin, in_);
    for (int j = 0; j < w; j++)
    {
      switch (in_[j])
      {
      case '.':
        line.push_back(Tile::EMPTY);
        break;
      case '#':
        line.push_back(Tile::BLOCK);
        break;
      case '@':
        line.push_back(Tile::BOOSTER);
        bstn[i][j] = bstn_______;
        bstn_______++;
        break;
      case 'S':
        line.push_back(Tile::EMPTY);
        start = {j, i};
        break;
      case 'T':
        line.push_back(Tile::EMPTY);
        target = {j, i};
        break;
      default:
        break;
      }
    }

    board.push_back(line);
  }

  visited[{
      {start.x, start.y},
      {1, 1}}] = {0, {{start.x, start.y}, {1, 1}}};

  FiledQ filedQ;
  filedQ.push(0, {{start.x, start.y}, {1, 1}});

  while (true)
  {
    int cost = filedQ.getCost();
    vector<Status> currentStatuses = filedQ.get();
    for (const auto &qfx : currentStatuses)
    {
      QData qf = {cost, qfx};

      if (X(qf) == target.x && Y(qf) == target.y)
      {
        cout << Cost(qf) << "\n";
        // backtrack
        vector<Status> path;
        Status current = qf.second;
        while (current != visited[current].second)
        {
          path.push_back(current);
          current = visited[current].second;
        }
        path.push_back(current);
        // path.push_back({{start.x, start.y}, {1, 1}});
        reverse(path.begin(), path.end());
        // cout << "0: " << path[0].first.first << " " << path[0].first.second << "\n";
        for (int i = 1; i < path.size(); i++)
        {
          // cout << "NOW AT " << path[i].first.first << " " << path[i].first.second << "\n";
          // get direction by W,A,S,D
          int dx = path[i].first.first - path[i - 1].first.first;
          int dy = path[i].first.second - path[i - 1].first.second;
          if (dx > 0 && dy == 0)
          {
            cout << "D";
          }
          else if (dx < 0 && dy == 0)
          {
            cout << "A";
          }
          else if (dx == 0 && dy > 0)
          {
            cout << "S";
          }
          else if (dx == 0 && dy < 0)
          {
            cout << "W";
          }
          else
          {
            cout << "X";
          }

          // print dist
          cout << " " << abs(dx) + abs(dy) << "\n";
        }
        return 0;
      }

      if (visited.find(qf.second) != visited.end() &&
          visited[qf.second].first < Cost(qf))
        continue;

      for (int dir = 0; dir < 4; dir++)
      {
        for (int moves = 1; moves <= Booster(qf); moves++)
        {
          int nx = X(qf) + dx[dir] * moves;
          int ny = Y(qf) + dy[dir] * moves;

          if (nx < 0 || nx >= w || ny < 0 || ny >= h)
            break;

          Tile tile = board[ny][nx];
          if (tile == Tile::BLOCK)
            break;

          char boosterTile = bstn[ny][nx];
          bool canUseBooster = tile == Tile::BOOSTER && !((1 << boosterTile) & Used(qf));

          Status nextStatus = {{nx, ny}, {Booster(qf) + (canUseBooster ? 1 : 0), Used(qf) | (canUseBooster ? (1 << boosterTile) : 0)}};

          if (visited.find(nextStatus) == visited.end() ||
              visited[nextStatus].first > Cost(qf) + 1)
          {
            visited[nextStatus] = {Cost(qf) + 1, qf.second};
            filedQ.push(Cost(qf) + 1, nextStatus);
          }
        }
      }
    }
  }
}
