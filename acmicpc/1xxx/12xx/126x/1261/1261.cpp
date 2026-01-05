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

using Pos = pair<int, int>;

int w, h;
// false = empty, true = wall
bool board[105][105] = {
    false,
};

int dist[105][105] = {
    0,
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> w >> h;
  for (int i = 0; i < h; i++)
  {
    string x;
    cin >> x;
    for (int j = 0; j < w; j++)
    {
      if (x[j] == '1')
        board[i][j] = true;
    }
  }

  memset(dist, 0x3f, sizeof(dist));
  dist[0][0] = 0;

  priority_queue<
      pair<int, Pos>,
      vector<pair<int, Pos>>,
      greater<pair<int, Pos>>>
      pq;

  pq.push({0, {0, 0}});

  while (!pq.empty())
  {
    pair<int, Pos> cur = pq.top();
    pq.pop();

    int curDist = cur.first;
    int cx = cur.second.first;
    int cy = cur.second.second;

    if (dist[cy][cx] < curDist)
      continue;

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];

      if (nx < 0 || nx >= w || ny < 0 || ny >= h)
        continue;

      int ndist = curDist + (board[ny][nx] ? 1 : 0);
      if (dist[ny][nx] > ndist)
      {
        dist[ny][nx] = ndist;
        pq.push({ndist, {nx, ny}});
      }
    }
  }
  cout << dist[h - 1][w - 1] << "\n";
}
