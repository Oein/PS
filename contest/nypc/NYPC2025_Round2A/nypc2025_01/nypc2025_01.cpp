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

int n, k;

vector<ll> v;

ll gltg = 0;
ll cost(ll target)
{
  gltg = target;
  sort(v.begin(), v.end(), [](ll a, ll b)
       { return abs(a - gltg) < abs(b - gltg); });

  ll res = 0;
  for (int i = 0; i < k; i++)
  {
    res += abs(v[i] - gltg);
  }
  return res;
}

void sol1()
{
  ll ans = LLONG_MAX;
  for (ll tgt = 0; tgt <= 100; tgt++)
  {
    ll cost_ = cost(tgt);
    if (ans > cost_)
    {
      ans = cost_;
    }
  }

  cout << ans;
}

void sol2()
{
  vector<ll> sum(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    sum[i + 1] = sum[i] + v[i];
  }

  ll ans = LLONG_MAX;

  for (int i = 0; i < n; i++)
  {
    int sl = max(0, i - (k - 1));
    int el = i;

    for (int l = sl; l <= el; l++)
    {
      int r = l + k - 1;
      if (r >= n)
        break;

      ll cost = 0;
      ll ls = sum[i] - sum[l];
      cost += (ll)(i - l) * v[i] - ls;

      ll rs = sum[r + 1] - sum[i + 1];
      cost += rs - (ll)(r - i) * v[i];

      ans = min(ans, cost);
    }
  }
  cout << ans;
}

void sol3()
{
  vector<ll> sum(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    sum[i + 1] = sum[i] + v[i];
  }

  ll ans = LLONG_MAX;

  for (int i = 0; i <= n - k; ++i)
  {
    int l = i;
    int r = i + k - 1;
    int mid = i + (k - 1) / 2;
    ll midVal = v[mid];

    ll lCnt = mid - l;
    ll lSum = sum[mid] - sum[l];
    ll now = lCnt * midVal - lSum;

    ll rCnt = r - mid;
    ll rSum = sum[r + 1] - sum[mid + 1];
    now += rSum - rCnt * midVal;

    ans = min(ans, now);
  }

  cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  if (k == 1)
  {
    cout << 0;
    return 0;
  }

  bool inside0100 = 1;
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    v.push_back(x);

    if (x < 0 || x > 100)
      inside0100 = 0;
  }

  sort(v.begin(), v.end());

  if (n <= 3000)
  {
    sol2();
    return 0;
  }

  if (inside0100)
  {
    sol1();
    return 0;
  }

  sol3();
}
