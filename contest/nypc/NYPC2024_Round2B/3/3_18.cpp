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

vector<pair<int, int>> v;
vector<pair<int, int>> ansv;

ull nans = 0;
ull ans = 0;
set<int> used;

int n;

vector<Pos> points;

void dfs(int idx)
{
  assert(nans >= 0);
  // cout << idx << '\n';
  if (idx == n)
  {
    assert(v.size() == n / 2);
    // printf("ANS: %lld NANS : %lld\n", ans, nans);

    if (ans < nans)
    {
      ans = nans;
      while (ansv.empty() == false)
      {
        ansv.pop_back();
      }

      for (auto p : v)
      {
        ansv.push_back(p);
      }
    }
    return;
  }
  if (used.find(idx) != used.end())
    return dfs(idx + 1);

  // idx와 idx + 1을 연결할끼라
  used.insert(idx);
  for (int i = idx + 1; i < n; i++)
  {
    if (used.find(i) != used.end())
      continue;
    used.insert(i);
    v.push_back({idx, i});
    nans += calcDist(points[idx], points[i]);
    dfs(idx + 1);
    nans -= calcDist(points[idx], points[i]);
    v.pop_back();
    used.erase(i);
  }
  used.erase(idx);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    Pos p;
    p.idx = i + 1;
    cin >> p.x >> p.y;
    points.push_back(p);
  }

  sort(points.begin(), points.end(), [](const Pos &a, const Pos &b)
       {
    if (a.x == b.x)
    {
      return a.y < b.y;
    }
    return a.x < b.x; });

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
}
