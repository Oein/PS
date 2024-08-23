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

int dx[] = {0, 0, 1, -1, 0};
int dy[] = {1, -1, 0, 0, 0};

struct Pos
{
  int x;
  int y;
};

int n, m, k;

vector<string> board;
bool visited[1005][1005][11][2] = {
    0,
};

#define debug \
  if (0)      \
  printf

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
  {
    string x;
    cin >> x;
    board.push_back(x);
  }

  queue<pair<Pos, int>> q;
  q.push({{0, 0}, k});
  visited[0][0][k][0] = 1;

  int t = 1;
  while (!q.empty())
  {
    unsigned long qs = q.size();
    const bool canBreak = t % 2 == 1;
    debug("t: %d, canBreak: %d\n", t, canBreak);
    while (qs--)
    {
      auto qf = q.front();
      q.pop();

      debug("  At X:%d Y:%d BR:%d\n", qf.first.x, qf.first.y, qf.second);

      if (qf.first.x == m - 1 && qf.first.y == n - 1)
      {
        cout << t;
        return 0;
      }

      for (int i = 0; i < 5; i++)
      {
        int nx = qf.first.x + dx[i];
        int ny = qf.first.y + dy[i];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
          continue;

        if (nx == 1 && ny == 1)
        {
          debug("NOO    nx: %d, ny: %d, BR: %d, canBreak: %d\n", nx, ny, qf.second, canBreak);
        }

        if (i == 4)
        {
          if (visited[ny][nx][qf.second][canBreak])
          {
            if (nx == 1 && ny == 1)
              debug("NOO    CN3\n");
            continue;
          }
          visited[ny][nx][qf.second][canBreak] = 1;
          q.push({{nx, ny}, qf.second});
        }
        else if (board[ny][nx] == '1' && qf.second > 0 && canBreak)
        {
          if (visited[ny][nx][qf.second - 1][canBreak])
          {
            if (nx == 1 && ny == 1)
              debug("NOO    CN1\n");
            continue;
          }
          visited[ny][nx][qf.second - 1][canBreak] = 1;
          q.push({{nx, ny}, qf.second - 1});
        }
        else if (board[ny][nx] == '0')
        {
          if (visited[ny][nx][qf.second][canBreak])
          {
            if (nx == 1 && ny == 1)
              debug("NOO    CN2\n");
            continue;
          }
          visited[ny][nx][qf.second][canBreak] = 1;
          q.push({{nx, ny}, qf.second});
        }
      }
    }
    t++;
  }

  cout << -1;
}
