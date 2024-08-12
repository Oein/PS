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
using namespace std;

int pth[300005] = {1, 1};
set<int> revpath[300005];
int a[300005] = {
    1972,
};
int n;

void dooper(int loc) {
  cout << a[loc] << "\n";
  vector<pair<int, int>> v;
  for (auto x : revpath[loc]) {
    v.push_back({a[x], x});
  }
  sort(v.begin(), v.end());
  for (auto x : v) {
    dooper(x.second);
  }
}

int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> pth[i];
    revpath[pth[i]].insert(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  dooper(1);
}
