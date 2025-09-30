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

  int n, l;
  cin >> n >> l;

  // 개수 X
  // Starter S
  // sum = X * (X + 1) / 2 + S * X
  // sum = X * (X + 1 + 2S) / 2
  // 2 * sum = X^2 + X + 2SX
  // 2SX = 2 * sum - X^2 - X
  // S = (2 * sum - X^2 - X) / (2 * X)

  for (int x = l; x <= 100; x++)
  {
    int sa = (2 * n - x * x - x);
    int sb = (2 * x);
    if (sa % sb != 0)
      continue;
    int s = sa / sb + 1;
    if (s < 0)
      continue;
    for (int i = 0; i < x; i++)
    {
      cout << s + i << (i == x - 1 ? "\n" : " ");
    }
    return 0;
  }

  cout << -1;
  return 0;
}
