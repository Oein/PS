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

int c, n;
//
int dp[1111] = {};
vector<pair<int, int>> markettings;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> c >> n;
  dp[0] = 0;
  for (int i = 1; i <= c + 100; ++i)
    dp[i] = zx3f;

  for (int i = 0; i < n; ++i)
  {
    int cost, people;
    cin >> cost >> people;
    markettings.push_back({cost, people});
  }

  for (int target = 1; target <= c + 100; ++target)
  {
    for (int i = 0; i < n; ++i)
    {
      int cost = markettings[i].first;
      int people = markettings[i].second;
      int prev = max(0, target - people);
      dp[target] = min(dp[target], dp[prev] + cost);
    }
  }

  int ans = zx3f;
  for (int i = c; i <= c + 100; ++i)
  {
    ans = min(ans, dp[i]);
  }
  cout << ans << "\n";
}