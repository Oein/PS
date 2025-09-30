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

vector<ull> a;

int stw(int d)
{
  int usg = abs(d);

  for (int i = 1; i < a.size(); i++)
  {
    int nw = a[i];
    int tg = a[0] + d + i;

    if (nw == tg)
      continue;

    if (nw - 1 == tg)
    {
      usg++;
      continue;
    }

    if (nw + 1 == tg)
    {
      usg++;
      continue;
    }

    return zx3f;
  }

  return usg;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.push_back(x);
  }

  cout << min(stw(0), min(stw(1), stw(-1)));
}
