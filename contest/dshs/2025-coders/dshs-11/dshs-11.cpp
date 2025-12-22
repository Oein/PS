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

int seg[1000000 * 4] = {
    0,
};

int add2seg(int targetl = 0, int targetr = 0, int idx = 0, int l = 0, int r)
{
  if (l == r)
  {
    seg[idx]++;
    return seg[idx];
  }
  seg[idx] = max(add2seg(idx * 2, l, (l + r) / 2), add2seg(idx * 2 + 1, (l + r) / 2, r));
  return seg[idx];
}

int getMaxSeg()
{
  return seg[0];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<Pos> p;
  for (int i = 0; i < n; i++)
  {
    Pos x;
    cin >> x.x >> x.y;
    }
}
