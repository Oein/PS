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
vector<int> items;

int gcd(int a, int b)
{
  while (b)
  {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

map<pair<int, int>, int> gcdCache;
int gcdRange(int a, int b)
{
  if (a == b)
    return items[a];
  auto key = make_pair(a, b);
  if (gcdCache.find(key) != gcdCache.end())
    return gcdCache[key];
  int res = items[a];
  for (int i = a; i <= b; ++i)
  {
    res = gcd(res, items[i]);
  }
  gcdCache[key] = res;
  return res;
}

int calc(int a, int b)
{
  if (a == b)
    return items[a];
  int mid = (a + b - 1) / 2;

  int leftGcd = calc(a, mid) + gcdRange(mid + 1, b);
  int rightGcd = calc(mid + 1, b) + gcdRange(a, mid);
  return max(leftGcd, rightGcd);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  items.resize(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> items[i];
  }
  cout << calc(0, n - 1);
}
