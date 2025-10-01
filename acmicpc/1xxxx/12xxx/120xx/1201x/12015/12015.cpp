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
int a[1000005]; // a[i] = i번째 수
int d[1000005]; // d[i] = i번째 까지 고려했을 때 LIS의 길이
int m[1000005]; // m[i] = LIS의 길이가 i인 수열에서 마지막 수의 최솟값

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    m[i] = zx3f;
    cin >> a[i];
  }

  m[0] = 0;
  a[0] = 0;
  d[0] = 0;

  int mx = 0;
  for (int targetTo = 1; targetTo <= n; targetTo++)
  {
    const int target = a[targetTo];
    const int pos = (int)(lower_bound(m, m + n + 1, target) - m);
    d[targetTo] = pos;
    m[pos] = min(m[pos], target);

    mx = max(mx, pos);
  }

  cout << mx << "\n";
}
