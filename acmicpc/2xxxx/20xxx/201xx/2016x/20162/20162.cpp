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
  vector<int> arr;
  // sum, maxValue
  vector<pair<int, int>> lis;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    arr.push_back(x);
    lis.push_back({x, x});
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[i] > arr[j])
      {
        int sum = lis[j].first + arr[i];
        int mx = max(lis[j].second, arr[i]);
        if (sum > lis[i].first)
        {
          lis[i] = {sum, mx};
        }
        else if (sum == lis[i].first)
        {
          lis[i].second = min(lis[i].second, mx);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, lis[i].first);
  }

  cout << ans << "\n";
}
