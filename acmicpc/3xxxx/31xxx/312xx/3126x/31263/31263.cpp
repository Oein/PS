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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  string s;
  cin >> n >> s;

  vector<int> dp(n + 1, zx3f);
  dp[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    int val = 0;
    int mul = 1;

    for (int j = 1; j <= 3; j++)
    {
      int start = i - j;
      if (start < 0)
        break;

      val = (s[start] - '0') * mul + val;
      mul *= 10;

      if (s[start] == '0')
        continue;
      if (val < 1 || val > 641)
        continue;

      dp[i] = min(dp[i], dp[start] + 1);
    }
  }

  cout << dp[n];
}
