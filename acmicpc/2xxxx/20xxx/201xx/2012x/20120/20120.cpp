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

int n;
vector<ll> scores;
// dp[combo] = 현재 콤보가 combo일 때 최대 점수
// miss_dp[m] = 미스가 m개일 때 최대 점수, m = 1 or 2
vector<ll> dp, new_dp;
ll miss_dp[3];

const ll NEG_INF = -1e18;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  scores.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> scores[i];
    dp.push_back(NEG_INF);
    new_dp.push_back(NEG_INF);
  }

  dp.push_back(NEG_INF);
  new_dp.push_back(NEG_INF);

  dp[0] = 0;
  miss_dp[1] = miss_dp[2] = NEG_INF;

  for (int i = 0; i < n; i++)
  {
    ll score = scores[i];
    for (int j = 0; j < n + 1; j++)
      new_dp[j] = NEG_INF;
    ll new_miss_dp[3] = {0, NEG_INF, NEG_INF};

    for (int c = 0; c <= i; c++)
    {
      if (dp[c] == NEG_INF)
        continue;

      new_dp[c + 1] = max(new_dp[c + 1], dp[c] + (ll)(c + 1) * score);
      new_miss_dp[1] = max(new_miss_dp[1], dp[c]);
    }

    if (miss_dp[1] != NEG_INF)
    {
      new_dp[1] = max(new_dp[1], miss_dp[1] + score);
      new_miss_dp[2] = max(new_miss_dp[2], miss_dp[1]);
    }

    if (miss_dp[2] != NEG_INF)
      new_dp[1] = max(new_dp[1], miss_dp[2] + score);

    dp = new_dp;
    miss_dp[1] = new_miss_dp[1];
    miss_dp[2] = new_miss_dp[2];
  }

  ll ans = 0;
  for (int c = 0; c <= n; c++)
    ans = max(ans, dp[c]);

  if (miss_dp[1] != NEG_INF)
    ans = max(ans, miss_dp[1]);
  if (miss_dp[2] != NEG_INF)
    ans = max(ans, miss_dp[2]);

  cout << ans << "\n";
  return 0;
}
