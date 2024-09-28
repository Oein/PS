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

int t[200005] = {
    0,
};
int s[200005] = {
    0,
};

pair<int, int> cache[200005] = {{0, 0}};
int lcached = 200005;

int main()
{
  memset(cache, 0, sizeof(cache));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> app;
  for (int i = 0; i < n; i++)
  {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    app.push_back({t[i], s[i]});
  }

  sort(app.begin(), app.end(), [](const pair<int, int> a, const pair<int, int> b)
       {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first; });

  sort(t, t + n);
  // 맛 값이 t 이상 가장 큰놈의 개수

  // for (auto ap : app)
  // {
  //   cout << "taste " << ap.first << " size " << ap.second << '\n';
  // }

  int sz = app[n - 1].second, cnt = 1;
  cache[n - 1] = {sz, cnt};
  // cout << n - 1 << " : " << sz << " | " << cnt << '\n';
  for (int i = n - 2; i >= 0; i--)
  {
    int nsz = app[i].second;
    if (nsz > sz)
    {
      cnt = 1;
      sz = nsz;
    }
    else if (nsz == sz)
    {
      cnt++;
    }

    cache[i] = {sz, cnt};
    // cout << i << " : " << sz << " | " << cnt << "\n";
  }

  while (q--)
  {

    int p;
    cin >> p;

    // cout << "=====++SEQ\n";

    // 맛 값이 t 이상이면서 사이즈가 가장 커야함.

    auto upb = lower_bound(t, t + n, p);
    int idx = upb - t;
    // cout << "UPB IDX " << idx << '\n';

    cout << cache[idx].second << "\n";
  }
}