#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <functional>
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

struct Class {
  int start;
  int end;
};

vector<Class> classes;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    Class cl;
    cin >> cl.start >> cl.end;
    classes.push_back(cl);
  }

  auto cmp = [](const Class a, const Class b) {
    if (a.start == b.start)
      return a.end < b.end;
    return a.start < b.start;
  };

  sort(classes.begin(), classes.end(), cmp);

  priority_queue<int, vector<int>, greater<int>> pq;

  int ans = 0;
  for (auto cl : classes) {
    if (pq.empty()) {
      ans++;
      pq.push(cl.end);
      continue;
    }

    int qf = pq.top();

    if (qf <= cl.start) {
      pq.pop();
      ans--;
    }
    ans++;
    pq.push(cl.end);
  }

  cout << ans;
}
