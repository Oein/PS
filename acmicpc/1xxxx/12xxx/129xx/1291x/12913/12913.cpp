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
typedef int u8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

typedef pair<double, pair<int, int>> QItem;

vector<double> cost[50];
double minT[55][55] = {
    0,
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  u8 n;
  u8 k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    string st;
    cin >> st;
    for (int j = 0; j < n; j++)
    {
      cost[i].push_back(st[j] - '0');
    }

    for (int j = 0; j <= k; j++)
    {
      minT[j][i] = zx3f;
    }
  }

  priority_queue<QItem, vector<QItem>, greater<QItem>> q;
  q.push({0.0, {0, k}});
  minT[k][0] = 0;
  while (!q.empty())
  {
    QItem qf = q.top();
    q.pop();

    if (qf.second.first == 1)
    {
      cout << qf.first;
      return 0;
    }

    for (u8 t = 0; t < n; t++)
    {
      if (t == qf.second.first)
        continue;

      double nextReq = qf.first + cost[qf.second.first][t];
      if (minT[qf.second.second][t] > nextReq)
      {
        minT[qf.second.second][t] = nextReq;
        q.push({nextReq, {t, qf.second.second}});
      }

      if (qf.second.second > 0)
      {
        double nextReq = qf.first + cost[qf.second.first][t] / 2;
        if (minT[qf.second.second - 1][t] > nextReq)
        {
          minT[qf.second.second - 1][t] = nextReq;
          q.push({nextReq, {t, (qf.second.second - 1)}});
        }
      }
    }
  }
}
