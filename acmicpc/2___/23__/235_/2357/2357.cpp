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

int n, m;
vector<int> arr;
vector<int> seg_min;
vector<int> seg_max;

void build(int node, int start, int end)
{
  if (start == end)
  {
    seg_min[node] = arr[start];
    seg_max[node] = arr[start];
    return;
  }

  int mid = (start + end) / 2;
  build(2 * node + 1, start, mid);
  build(2 * node + 2, mid + 1, end);
  seg_min[node] = min(seg_min[2 * node + 1], seg_min[2 * node + 2]);
  seg_max[node] = max(seg_max[2 * node + 1], seg_max[2 * node + 2]);
}

int query_min(int node, int start, int end, int l, int r)
{
  if (r < start || end < l)
    return zx3f;
  if (l <= start && end <= r)
    return seg_min[node];
  int mid = (start + end) / 2;
  int p1 = query_min(2 * node + 1, start, mid, l, r);
  int p2 = query_min(2 * node + 2, mid + 1, end, l, r);
  return min(p1, p2);
}

int query_max(int node, int start, int end, int l, int r)
{
  if (r < start || end < l)
    return -zx3f;
  if (l <= start && end <= r)
    return seg_max[node];
  int mid = (start + end) / 2;
  int p1 = query_max(2 * node + 1, start, mid, l, r);
  int p2 = query_max(2 * node + 2, mid + 1, end, l, r);
  return max(p1, p2);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  arr.resize(n);
  seg_min.resize(4 * n);
  seg_max.resize(4 * n);
  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i];
  }
  build(0, 0, n - 1);

  for (int i = 0; i < m; ++i)
  {
    int a, b;
    cin >> a >> b;
    cout << query_min(0, 0, n - 1, a - 1, b - 1) << " " << query_max(0, 0, n - 1, a - 1, b - 1) << "\n";
  }
}
