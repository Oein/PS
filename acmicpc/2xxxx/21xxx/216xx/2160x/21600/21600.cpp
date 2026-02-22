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

  vector<ll> a;
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    a.push_back(x);
  }

  deque<int> dq;
  int answer = 0;
  int l = 0;

  for (int r = 0; r < n; r++)
  {
    ll cur = a[r] - r;
    while (!dq.empty() && (a[dq.back()] - dq.back()) >= cur)
    {
      dq.pop_back();
    }
    dq.push_back(r);

    while (!dq.empty() && (a[dq.front()] - dq.front()) < (1LL - l))
    {
      if (dq.front() == l)
      {
        dq.pop_front();
      }
      l++;
    }

    answer = max(answer, r - l + 1);
  }

  cout << answer;
}
