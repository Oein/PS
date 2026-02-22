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

bool to[11][11] = {
    0,
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll a, b, c;
  cin >> a >> b >> c;

  for (int x = 1; x <= 10; x++)
    for (int y = 1; y <= 10; y++)
      if (a * x + b * y == c)
        to[x][y] = true;

  for (int i = 1; i <= 10; i++)
  {
    bool c = false;
    for (int j = 1; j <= 10; j++)
    {
      if (to[i][j])
      {
        if (c)
          cout << ' ';
        cout << j;
        c = true;
      }
    }

    if (!c)
      cout << 0;
    cout << '\n';
  }

  return 0;
}
