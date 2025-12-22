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
typedef long long ull;

#define interface struct

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

ll safeNum(ll n)
{
  return n % 1000000007LL;
}

ll sol()
{
  int n;
  cin >> n;

  vector<int> books;
  bool n2m[2005] = {
      0,
  };
  for (int i = 0; i < n; i++)
  {
    n2m[i + 1] = true;

    ll x;
    cin >> x;

    if (x > 1LL)
      books.push_back(x); // 0!, 1! = 1 -> 나누눈데 필요 없음
  }

  ll res = 1;
  for (ll divideUp2 : books)
  {
    for (ll divideWith = 2; divideWith <= divideUp2; divideWith++)
    {
      if ((res % divideWith) == 0)
      {
        res /= divideWith;
        continue;
      }

      for (int multiply = 2; multiply <= n; multiply++)
      {
        if (!n2m[multiply])
        {
          // 곱할 필요가 없다? 이미 곱해진 숫자다
          continue;
        }

        if (((ll)multiply % divideWith) == 0)
        {
          n2m[multiply] = false;
          res = safeNum(((ll)multiply / divideWith) * res);
          break;
        }
      }
    }
  }

  for (int multiply = 2; multiply <= n; multiply++)
  {
    if (n2m[multiply])
    {
      res = safeNum(res * (ll)multiply);
    }
  }

  return res;
}

int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    ll r = sol();
    if (i == t - 1)
      cout << r;
    else
      cout << r << '\n';
  }
}
