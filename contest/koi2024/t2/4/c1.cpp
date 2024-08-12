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
  if (revpath[loc].size() == 0) {
    // leaf node
    // 부모에서 자신을 삭제
    revpath[pth[loc]].erase(loc);

    return;
  }

  int minAC = INT_MAX;
  int minACP = 0;
  for (auto x : revpath[loc]) {
    int nac = a[x];
    if (minAC > nac) {
      minAC = nac;
      minACP = x;
    }
  }

  // 가장작은 간선 확인
  swap(a[loc], a[minACP]);
  dooper(minACP);
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

  for (int i = 1; i <= n; i++) {
    cout << a[1] << "\n";
    dooper(1);
  }
}
