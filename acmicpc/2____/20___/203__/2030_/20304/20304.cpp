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

int toReach[1000005] = {0};

int main()
{
  memset(toReach, -1, sizeof(toReach));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  queue<int> q;
  int stp = 0;

  for (int i = 0; i < m; i++)
  {
    int p;
    cin >> p;
    q.push(p);
    toReach[p] = 0;
  }

  while (!q.empty())
  {
    unsigned long qs = q.size();
    while (qs--)
    {
      auto qf = q.front();
      q.pop();

      // cout << "At " << qf << " with " << stp << endl;

      for (int i = 0; i < 20; i++)
      {
        int next = qf ^ (1 << i);
        if (next > n)
          continue;
        // cout << "NXT " << next << " TRC " << toReach[next] << endl;
        if (toReach[next] == -1)
        {
          toReach[next] = stp + 1;
          q.push(next);
        }
      }
    }
    stp++;
  }

  sort(toReach, toReach + 1 + n, greater<int>());
  cout << toReach[0] << endl;
  // for (int i = 0; i < n; i++)
  // {
  //   cout << toReach[i] << " ";
  // }
}
