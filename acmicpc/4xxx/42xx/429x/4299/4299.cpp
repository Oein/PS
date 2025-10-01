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

  int sum, min = 0;
  cin >> sum >> min;
  // x + y = s
  // x - y = m
  // 2x = s + m
  // 2y = s - m
  int x = (sum + min) / 2;
  int y = (sum - min) / 2;
  if (x < 0 || y < 0 || (sum + min) % 2 != 0 || (sum - min) % 2 != 0)
  {
    cout << -1;
    return 0;
  }

  if (x < y)
    swap(x, y);
  cout << x << " " << y;
}
