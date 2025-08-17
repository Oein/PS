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
  ll x;
  ll y;
  ll idx;
};

ull calcDist(const Pos &a, const Pos &b)
{
  return abs(a.x - b.x) + abs(a.y - b.y);
}

vector<pair<int, int>> pairs;
ull ans = 0;
set<int> used;

int n;
vector<Pos> points;

ll pr = 0;
vector<pair<int, int>> ansv;

void dfs(int idx)
{
  if (used.size() >= n || idx >= n)
  {
    if (ans >= pr)
    {
      pr = ans;
      ansv = pairs;
    }
    return;
  }

  if (idx != 0 && used.find(idx) != used.end())
  {
    return dfs(idx + 1);
  }

  for (int i = idx + 1; i < n; i++)
  {
    if (used.find(i) != used.end())
    {
      continue;
    }

    used.insert(i);
    pairs.push_back({idx, i});
    ans += calcDist(points[idx], points[i]);
    dfs(idx + 1);
    ans -= calcDist(points[idx], points[i]);
    pairs.pop_back();
    used.erase(i);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  long long yx = 0;
  bool ysame = true;
  for (int i = 0; i < n; i++)
  {
    Pos p;
    p.idx = i + 1;
    cin >> p.x >> p.y;
    if (i == 0)
      yx = p.y;
    else if (yx != p.y)
      ysame = false;
    points.push_back(p);
  }

  if (ysame)
  {
    sort(points.begin(), points.end(), [](const Pos &a, const Pos &b)
         { return a.x < b.x; });

    ll ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
      int fromBack = n - i - 1;
      ans += calcDist(points[i], points[fromBack]);
    }
    cout << ans << '\n';
    for (int i = 0; i < n / 2; i++)
    {
      cout << points[i].idx << ' ' << points[n - i - 1].idx << '\n';
    }

    return 0;
  }

  used.insert(0);
  dfs(0);

  cout << pr << '\n';
  for (auto &p : ansv)
  {
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  }
}
