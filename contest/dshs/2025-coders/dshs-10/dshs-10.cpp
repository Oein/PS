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

int n, r1, r2;

using P = pair<int, int>;
vector<P> problems;

vector<set<int>> dp[305][305];
bool cachedr1[305] = {
    0,
};
bool cachedr2[305] = {
    0,
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> r1 >> r2;

  int maxR1Ad = 0;
  int maxR2Ad = 0;
  int minR1 = 1234567890;
  int minR2 = 1234567890;
  for (int i = 0; i < n; i++)
  {
    P a;
    cin >> a.first >> a.second;

    maxR1Ad += a.first;
    maxR2Ad += a.second;

    minR1 = min(minR1, a.first);
    minR2 = min(minR2, a.second);

    problems.push_back(a);
  }

  if (maxR1Ad < r1 || maxR2Ad < r2)
  {
    cout << -1;
    return 0;
  }

  cachedr1[0] = 1;
  cachedr2[0] = 1;
  vector<set<int>> ev;
  set<int> es;
  ev.push_back(es);
  dp[0][0] = ev;
  int minSol = 1234567890;

  for (int targetR1 = minR1 - 1; targetR1 <= 300; targetR1++)
  {
    bool canMakeR1 = false;
    for (int i = 0; i < n; i++)
    {
      P p = problems[i];
      int or1 = targetR1 - p.first;
      if (or1 < 0)
        continue;
      if (!cachedr1[or1])
        continue;
      canMakeR1 = true;
    }

    if (!canMakeR1)
      continue;

    for (int targetR2 = minR2 - 1; targetR2 <= 300; targetR2++)
    {
      for (int i = 0; i < n; i++)
      {
        P p = problems[i];
        int or1 = targetR1 - p.first;
        if (or1 < 0)
          continue;
        if (!cachedr1[or1])
          continue;

        int or2 = targetR2 - p.second;
        if (or2 < 0)
          continue;
        if (!cachedr2[or2])
          continue;

        set<set<int>> hasNSet;
        vector<set<int>> ndp;
        int minCnt = 1234567890;
        for (set<int> oldset : dp[or1][or2])
        {
          if (oldset.find(i) != oldset.end())
            continue;

          oldset.insert(i);
          if (minCnt < oldset.size())
            continue;
          if (hasNSet.find(oldset) != hasNSet.end())
            continue;

          if (minCnt > oldset.size())
          {
            hasNSet.clear();
            ndp.clear();
            minCnt = oldset.size();
          }
          hasNSet.insert(oldset);
          ndp.push_back(oldset);
        }

        dp[targetR1][targetR2] = ndp;
        if (ndp.size() > 0)
        {
          cachedr1[targetR1] = 1;
          cachedr2[targetR2] = 1;
        }
      }

      if (dp[targetR1][targetR2].size() > 0 && targetR1 >= r1 && targetR2 >= r2)
      {
        if (minSol > dp[targetR1][targetR2][0].size())
        {
          minSol = dp[targetR1][targetR2][0].size();
        }
      }
    }
  }

  if (minSol == 1234567890)
    assert(false);
  else
    cout << minSol;
}
