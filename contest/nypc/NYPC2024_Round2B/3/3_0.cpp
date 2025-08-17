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
ll ans = 0;
set<int> used;

int n;
vector<Pos> points;

ll pr = 0;
vector<pair<int, int>> ansv;

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

  for (int i = 0; i < n; i++)
  {
    if (used.find(i) != used.end())
    {
      continue;
    }

    used.insert(i);

    ll maxV = 0;
    ll maxIdx = -1;
    for (int j = i + 1; j < n; j++)
    {
      if (used.find(j) != used.end())
      {
        continue;
      }

      ll dist = calcDist(points[i], points[j]);
      if (maxV < dist)
      {
        maxV = dist;
        maxIdx = j;
      }
    }
    used.insert(maxIdx);
    pairs.push_back({i, maxIdx});
    pr += maxV;
  }

  cout << pr << '\n';
  for (auto &p : pairs)
  {
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  }
}
