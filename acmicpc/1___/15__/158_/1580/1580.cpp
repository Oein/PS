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

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

struct Pos
{
  int x;
  int y;
};

set<int> __visited[21][21][21];

vector<vector<bool>> board;
int h, w;

Pos a, b;

struct QItem
{
  Pos a;
  Pos b;
};

bool visited(Pos a, Pos b)
{
  return __visited[a.x][a.y][b.x].find(b.y) != __visited[a.x][a.y][b.x].end();
}

void setVisited(Pos a, Pos b)
{
  __visited[a.x][a.y][b.x].insert(b.y);
}

bool inMap(Pos l)
{
  return l.x >= 0 && l.y >= 0 && l.x < w && l.y < h;
}

bool posEq(Pos a, Pos b)
{
  return a.x == b.x && a.y == b.y;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> h >> w;
  for (int i = 0; i < h; i++)
  {
    string boardLine;
    cin >> boardLine;
    vector<bool> mapLine;
    for (int j = 0; j < w; j++)
    {
      switch (boardLine[j])
      {
      case 'A':
        a = {j, i};
        mapLine.push_back(1);
        break;
      case 'B':
        b = {j, i};
        mapLine.push_back(1);
        break;
      case 'X':
        mapLine.push_back(0);
        break;
      case '.':
        mapLine.push_back(1);
        break;
      default:
        break;
      }
    }

    board.push_back(mapLine);
  }

  // for (vector<bool> b : board)
  // {
  //   for (bool bb : b)
  //   {
  //     cout << (bb ? "." : "X");
  //   }
  //   cout << "\n";
  // }

  setVisited(a, b);
  queue<QItem> q;
  q.push({a, b});

  int t = 0;
  while (!q.empty())
  {
    unsigned long qs = q.size();
    while (qs--)
    {
      QItem qf = q.front();
      q.pop();

      if (qf.a.x == b.x && qf.a.y == b.y)
        if (qf.b.x == a.x && qf.b.y == a.y)
        {
          cout << t;
          return 0;
        }

      // A 이동, B 이동
      // 1      1
      // 1      0
      // 0      1

      for (int mvA = 0; mvA < 9; mvA++)
      {
        Pos na = {qf.a.x + dx[mvA], qf.a.y + dy[mvA]};
        if (!inMap(na))
          continue;
        if (!board[na.y][na.x])
          continue;
        for (int mvB = 0; mvB < 9; mvB++)
        {
          Pos nb = {qf.b.x + dx[mvB], qf.b.y + dy[mvB]};
          if (!inMap(nb))
            continue;
          if (!board[nb.y][nb.x])
            continue;
          if (posEq(na, nb))
            continue;
          if (posEq(na, qf.b) && posEq(nb, qf.a))
            continue;
          if (visited(na, nb))
            continue;
          setVisited(na, nb);
          q.push({na, nb});
        }
      }
    }

    t++;
  }

  cout << -1;
  return 0;
}
