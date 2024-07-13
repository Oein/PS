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

struct Pos {
  int x;
  int y;
};

int dp[1005][3][3] = {
    0,
};
int n;
int cost[1005][3] = {
    0,
};
int sthouse = 0;

void indentPrint(int indent) {
  for (int i = 0; i < indent; i++)
    cout << " ";
}

int worker(int housenum, int rgb) {
  // indentPrint(housenum);
  // cout << "[" << housenum << "] " << rgb << endl;
  // housenum에서 현재 rgb로 색을 칠함
  if (housenum == n - 1) {
    if (rgb == sthouse)
      return 1000 * 1000;
    return cost[housenum][rgb];
  }
  // indentPrint(housenum);
  // cout << "WORKING\n";
  if (dp[housenum][rgb][sthouse] != -1)
    return dp[housenum][rgb][sthouse] + cost[housenum][rgb];

  // indentPrint(housenum);
  // cout << "WORKING\n";

  int ret = 1000 * 1000;

  for (int i = 0; i < 3; i++) {
    if (i == rgb)
      continue;
    ret = min(ret, worker(housenum + 1, i));
  }

  dp[housenum][rgb][sthouse] = ret;
  return ret + cost[housenum][rgb];
}

int main() {
  memset(dp, -1, sizeof(dp));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
  int minv = 1000 * 1000;
  for (int i = 0; i < 3; i++) {
    sthouse = i;
    minv = min(minv, worker(0, i));
  }
  cout << minv;
}
