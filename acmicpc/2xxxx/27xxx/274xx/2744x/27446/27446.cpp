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

  int n, m;
  cin >> n >> m;

  bool exi[105] = {
      0,
  };
  for (int i = 0; i < m; i++)
  {
    int p;
    cin >> p;
    exi[p] = true;
  }

  vector<int> ne;
  for (int i = 1; i <= n; i++)
    if (!exi[i])
      ne.push_back(i);

  if (ne.empty())
  {
    cout << 0;
    return 0;
  }

  int dp[105] = {
      0,
  };
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;

  for (int i = 1; i <= ne.size(); i++)
  {
    for (int j = 0; j < i; j++)
    {
      int cost = 5 + 2 * (ne[i - 1] - ne[j] + 1);
      dp[i] = min(dp[i], dp[j] + cost);
    }
  }

  cout << dp[ne.size()];
}
