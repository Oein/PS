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
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    v.push_back(a);
  }

  for (int t = 1; t <= n / 2; t++)
  {
    // t개를 체크
    bool ok = true;
    for (int check = 0; check < t; check++)
    {
      int l = check;
      int r = n - t + check;

      if (v[l] != v[r])
      {
        ok = false;
      }
    }

    if (ok)
    {
      cout << "yes";
      return 0;
    }
  }

  cout << "no";
}