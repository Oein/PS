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

  vector<string> f;
  for (int i = 0; i < n; i++)
  {
    string l;
    cin >> l;
    f.push_back(l);
  }

  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        continue;

      bool r = false;

      if (f[i][j] == 'Y')
        r = true;
      else
      {
        for (int k = 0; k < n; k++)
        {
          if (k == i || k == j)
            continue;
          if (f[i][k] == 'Y' && f[k][j] == 'Y')
          {
            r = true;
            break;
          }
        }
      }

      if (r)
        cnt++;
    }

    ans = max(ans, cnt);
  }

  cout << ans;
}
