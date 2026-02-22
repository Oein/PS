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

  string n;
  cin >> n;

  bool c = false;

  for (int i = 1; i < n.size(); i++)
  {
    long long l = 1;
    for (int j = 0; j < i; j++)
      l *= (n[j] - '0');

    long long r = 1;
    for (int j = i; j < n.size(); j++)
      r *= (n[j] - '0');

    if (l == r)
    {
      c = true;
      break;
    }
  }

  cout << (c ? "YES" : "NO");

  return 0;
}
