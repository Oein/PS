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
  ll x;
  ll y;
};

#define MOD 1000000007

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<ll> stp(n);

  for (int i = 0; i < n; i++)
  {
    cin >> stp[i];
  }

  ull ans = 0;
  // dp[i][j] = i번째 에서 diff가 j일때 만들 수 있는 계단의 개수
  map<ll, map<ll, ull>> dp;
  for (int i = n - 2; i >= 0; i--)
  {
    auto &m = dp[i];
    for (int j = n - 1; j > i; j--)
    {
      const ll diff = stp[j] - stp[i];
      if (m.find(diff) == m.end())
      {
        m[diff] = 0;
      }

      if (dp[j].find(diff) == dp[j].end())
      {
        m[diff] += 1LL;
      }
      else
      {
        m[diff] = (m[diff] + dp[j][diff] + 1LL);
        while (m[diff] >= MOD)
        {
          m[diff] -= MOD;
        }
      }
      // i에서 j까지 점프해서 diff만큼 차이가 남.
      // printf("%d에서 %d까지 %d만큼 점프해서 %d개의 개단을 만들 수 있음.\n", i, j, diff, dp[j][diff] + 1);
    }

    for (auto &p : m)
    {
      ans = (ans + p.second);
      while (ans >= MOD)
      {
        ans -= MOD;
      }
    }
  }

  // for (int i = 0; i < n; i++)
  // {
  //   for (auto &p : m)
  //   {
  //     ans = (ans + p.second) % MOD;
  //     printf("%d에서 %d만큼 차이가 나는 계단을 만들 수 있는 경우의 수: %d\n", i, p.first, p.second);
  //   }
  // }

  cout << ans << '\n';
}
