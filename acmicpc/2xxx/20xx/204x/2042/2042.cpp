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

int n, m, k;
vector<ll> arr;
vector<ll> seg;

void build(int node, int start, int end)
{
  if (start == end)
  {
    seg[node] = arr[start];
    return;
  }

  int mid = (start + end) / 2;
  build(2 * node + 1, start, mid);
  build(2 * node + 2, mid + 1, end);
  seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}

void update(int node, int start, int end, int idx, ll value)
{
  if (start == end)
  {
    arr[idx] = value;
    seg[node] = value;

    return;
  }

  int mid = (start + end) / 2;
  if (start <= idx && idx <= mid)
    update(2 * node + 1, start, mid, idx, value);
  else
    update(2 * node + 2, mid + 1, end, idx, value);

  seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}

ll query(int node, int start, int end, int l, int r)
{
  if (r < start || end < l)
    return 0;
  if (l <= start && end <= r)
    return seg[node];
  int mid = (start + end) / 2;
  ll p1 = query(2 * node + 1, start, mid, l, r);
  ll p2 = query(2 * node + 2, mid + 1, end, l, r);
  return p1 + p2;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  arr.resize(n);
  seg.resize(4 * n);
  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i];
  }
  build(0, 0, n - 1);

  for (int i = 0; i < m + k; ++i)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1)
      update(0, 0, n - 1, b - 1, c);
    else
      cout << query(0, 0, n - 1, b - 1, c - 1) << "\n";
  }
}
