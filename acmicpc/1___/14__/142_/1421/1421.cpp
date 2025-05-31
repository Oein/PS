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

int n, c, w;
vector<int> trees;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> c >> w;
  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t;
    trees.push_back(t);
    mx = max(mx, t);
  }

  ll mxErn = 0;
  for (int danwi = 1; danwi <= mx; danwi++)
  {
    ll earnCost = 0;
    for (ll tr : trees)
    {
      ll trCnt = tr / danwi;
      ll estCut = trCnt;
      if (tr % danwi == 0)
        estCut--;
      ll estCost = estCut * c;
      ll ern = trCnt * danwi * w - estCost;
      if (ern > 0)
        earnCost += ern;
    }
    // cout << "At " << danwi << "\tern " << earnCost << "\n";
    mxErn = max(mxErn, earnCost);
  }
  cout << mxErn;
}
