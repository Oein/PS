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
  vector<pair<int, int>> v;
  for (auto x : revpath[loc]) {
    v.push_back({a[x], x});
  }
  sort(v.begin(), v.end());
  for (auto x : v) {
    cout << a[x.second] << '\n';
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

  queue<int> q;

  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++)
    cout << a[i] << "\n";
}
