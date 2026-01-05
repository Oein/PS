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

// days, water
pair<int, int> dp[1000005] = {
    {0, 0}};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  memset(dp, 0x3f, sizeof(dp));
  dp[0] = {0, 0};
  dp[1] = {1, 1};

  int n;
  cin >> n;

  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1];
    dp[i].first += 1;
    dp[i].second += 1;

    if (i % 3 == 0)
    {
      int newWat = dp[i / 3].second + 3;
      int newDays = dp[i / 3].first + 1;
      if (dp[i].first > newDays || (dp[i].first == newDays && dp[i].second > newWat))
      {
        dp[i].first = newDays;
        dp[i].second = newWat;

        // cout << "UPD " << i << " from /3\n";
      }
    }

    if ((int)sqrt(i) * (int)sqrt(i) == i)
    {
      int newWat = dp[(int)sqrt(i)].second + 5;
      int newDays = dp[(int)sqrt(i)].first + 1;
      if (dp[i].first > newDays || (dp[i].first == newDays && dp[i].second > newWat))
      {
        dp[i].first = newDays;
        dp[i].second = newWat;

        // cout << "UPD " << i << " from sqrt\n";
      }
    }
  }

  // for (int i = 1; i <= n; i++)
  // {
  //   cout << i << " | " << dp[i].first << " " << dp[i].second << "\n";
  // }
  cout << dp[n].first << " " << dp[n].second;
}
