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
#define ull long long
ull l, n, k;

vector<ull> instpos;
vector<ull> diff;

int main() {
  cin >> l >> n >> k;

  ull lastpos = 0;
  for (int i = 0; i < n; i++) {
    ull x;
    cin >> x;
    instpos.push_back(x);
  }

  // 0 번째 부터의 거리
  diff.push_back(instpos[0]);

  for (int i = 1; i < n; i++) {
    diff.push_back(instpos[i] - instpos[i - 1] - 1LL);
  }

  // 끝까지 거리
  diff.push_back(l - instpos[n - 1]);

  // for(auto x : diff) cout << x <<" ";
  // cout << "\n";

  while (k > 0 && n > 0) {
    cout << 0 << "\n";
    k--;
    n--;
  }

  ull nowlightlevel = 0;
  ull printleft = 0;
  while (k > 0) {
    if (printleft == 0) {
      // process 0
      nowlightlevel++;

      if (diff[0] >= nowlightlevel)
        printleft++;
      if (diff[diff.size() - 1] >= nowlightlevel)
        printleft++;

      for (int i = 1; i < diff.size() - 1; i++) {
        const ull MAXL = (diff[i] + 1) / 2;
        if (nowlightlevel > MAXL)
          continue;

        const bool C2 = (diff[i] % 2) == 0;
        const bool ISC2 = MAXL == nowlightlevel;

        if (ISC2) {
          if (C2) {
            printleft++;
            printleft++;
          } else {
            printleft++;
          }
        } else {
          printleft++;
          printleft++;
        }
      }
    }

    while (k > 0 && printleft > 0) {
      cout << nowlightlevel << '\n';
      k--;
      printleft--;
    }
  }
}
