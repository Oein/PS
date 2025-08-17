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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  ll a = 0;
  set<ll> s;
  map<ll, ll> m;
  for (ll i = 1; i <= n; i++)
  {
    ll x;
    cin >> x;
    if (x > n)
    {
      a += i;
    }
    else if (s.find(x) != s.end())
    {
      a += m[x];
    }
    s.insert(x);
    m[x] = i;
  }

  cout << a << endl;
}
