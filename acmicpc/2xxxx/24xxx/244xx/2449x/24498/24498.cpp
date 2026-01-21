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
  vector<int> height;
  int mxAns = 0;
  for (int i = 0; i < n; i++)
  {
    int h;
    cin >> h;
    mxAns = max(mxAns, h);
    height.push_back(h);
  }

  for (int i = 1; i < n - 1; i++)
  {
    if (height[i - 1] && height[i + 1])
    {
      int minAd = min(height[i - 1], height[i + 1]);
      mxAns = max(mxAns, minAd + height[i]);
    }
  }

  cout << mxAns;
}
