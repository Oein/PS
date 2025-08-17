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

int n, m, k;

vector<string> board;

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

  int t = 1;
  while (!q.empty())
  {
    unsigned long qs = q.size();
    while (qs--)
    {
      auto qf = q.front();
      q.pop();

      if (qf.first.x == n - 1 && qf.first.y == m - 1)
      {
        cout << t;
        return 0;
      }

      for (int i = 0; i < 4; i++)
      {
        int nx = qf.first.x + dx[i];
        int ny = qf.first.y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;

        if (board[nx][ny] == '1' && qf.second > 0)
        {
          q.push({{nx, ny}, qf.second - 1});
        }
        else if (board[nx][ny] == '0')
        {
          q.push({{nx, ny}, qf.second});
        }
      }
    }
    t++;
  }

  cout << -1;
}
