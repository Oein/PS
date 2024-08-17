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

int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};

using Pos = pair<int, int>;
#define x first
#define y second

int r, c;

Pos me;
set<Pos> crazy;

string cmd;
vector<string> board;

int nstep = 0;

void processSelfMove()
{
  board[me.y][me.x] = '.';
  me.x += dx[cmd[nstep] - '1'];
  me.y += dy[cmd[nstep] - '1'];
  if (board[me.y][me.x] == 'R')
  {
    cout << "kraj " << nstep + 1;
    exit(0);
  }
  board[me.y][me.x] = 'I';
}

void processCrazyMove()
{
  vector<pair<Pos, Pos>> edit;
  set<Pos> in;
  set<Pos> rm;
  for (auto &cz : crazy)
  {
    int minDist = INT_MAX;
    Pos minPos = cz;
    for (int i = 0; i < 9; i++)
    {
      if (i == 4)
        continue;
      int nx = cz.x + dx[i];
      int ny = cz.y + dy[i];
      if (nx < 0 || nx >= c || ny < 0 || ny >= r)
        continue;
      int dist = abs(me.x - nx) + abs(me.y - ny);
      if (dist < minDist)
      {
        minDist = dist;
        minPos = {nx, ny};
      }
    }
    edit.push_back({cz, minPos});
    if (in.find(minPos) != in.end())
    {
      rm.insert(minPos);
    }
    in.insert(minPos);

    if (minPos == me)
    {
      cout << "kraj " << nstep + 1;
      exit(0);
    }
  }

  crazy.clear();

  for (auto &e : edit)
  {
    if (rm.find(e.second) == rm.end())
    {
      crazy.insert(e.second);
    }
    // cout << e.first.x << " " << e.first.y << " -> " << e.second.x << " " << e.second.y << '\n';
    board[e.first.y][e.first.x] = '.';
    board[e.second.y][e.second.x] = 'R';
  }

  for (auto &cz : rm)
  {
    board[cz.y][cz.x] = '.';
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> r >> c;

  for (int i = 0; i < r; i++)
  {
    string x;
    cin >> x;
    for (int j = 0; j < c; j++)
    {
      if (x[j] == 'I')
      {
        me = {j, i};
      }
      else if (x[j] == 'R')
      {
        crazy.insert({j, i});
      }
    }
    board.push_back(x);
  }

  cin >> cmd;
  for (int i = 0; i < cmd.size(); i++)
  {
    nstep = i;
    processSelfMove();
    processCrazyMove();

    // cout << "=================" << nstep << "====================\n";
    // for (int i = 0; i < r; i++)
    // {
    //   cout << board[i] << '\n';
    // }
  }

  // cout << "=================" << "LAST" << "====================\n";
  for (int i = 0; i < r; i++)
  {
    cout << board[i] << '\n';
  }
}
