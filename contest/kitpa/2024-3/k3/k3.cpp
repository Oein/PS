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
  cin >> n;
  int dx[200005] = {
      0,
  };
  for (int i = 0; i < n; i++)
  {
    int s, e, d;
    cin >> s >> e >> d;
    dx[i] = d;
  }
  sort(dx, dx + n);
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += (long long)dx[i] * ((long long)n - (long long)i - 1LL);
  }
  cout << ans * 2LL;
}

// 0 1 2 3 4 5
// 1 0 1 1 1 1
// 2 0 0 2 2 2
// 3 0 0 0 3 3
// 4 0 0 0 0 4
// 5 0 0 0 0 0

// 0 1 1 2 3 4
// 1 0 1 1 1 1
// 1 0 0 1 1 1
// 2 0 0 0 2 2
// 3 0 0 0 0 3
// 4 0 0 0 0 0