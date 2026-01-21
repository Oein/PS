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

map<int, ull> mp;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  ull ans = 0;

  for (int i = 0; i < n; i++)
  {
    int pos, time;
    ull earn;
    cin >> pos >> time >> earn;

    int bVal = time - pos;
    if (mp.find(bVal) != mp.end())
    {
      mp[bVal] += earn;
    }
    else
    {
      mp[bVal] = earn;
    }
  }
  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    ans = max(ans, it->second);
  }
  cout << ans;
}
