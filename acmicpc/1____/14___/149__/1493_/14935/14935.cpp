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

int f(int x)
{
  int xlen = 1;
  while (x > 10)
  {
    xlen++;
    x /= 10;
  }

  return xlen * x;
}

int f(string x)
{
  return x.size() * (x[0] - '0');
}

set<int> visited;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string n;
  cin >> n;

  int d = f(n);
  while (true)
  {
    int nd = f(d);
    if (d == nd)
    {
      cout << "FA";
      return 0;
    }

    if (visited.find(nd) != visited.end())
    {
      cout << "NFA";
      return 0;
    }

    visited.insert(nd);
    d = nd;
  }
}
