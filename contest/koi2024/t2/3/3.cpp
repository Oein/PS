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

#define ll long long

void printAsBin(ll num) {
  if (num == 0) {
    cout << 0;
    return;
  }
  stack<bool> s;
  while (num) {
    s.push(num % 2);
    num /= 2;
  }

  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
}

void rmain() {
  ll n;
  vector<bool> a;
  cin >> n;
  string x;
  cin >> x;
  for (auto y : x) {
    if (y == '0') {
      a.push_back(0);
    } else {
      a.push_back(1);
    }
  }

  ll mxbi = 0;
  ll mxmc = 0;
  for (ll st1 = 0; st1 < n; st1++)
    for (ll st2 = 0; st2 < n; st2++)
      for (ll ed2 = st2; ed2 < n; ed2++)
        for (ll ed1 = st1 + ed2 - st2 - 1; ed1 < n; ed1++) {
          ll alen = ed1 - st1 + 1;
          ll blen = ed2 - st2 + 1;
          if (alen < blen)
            continue;
          // 항상 윗 친구가 길게
          ll bi = 0;
          ll mc1 = 0;
          ll mc2 = 0;
          for (ll i = 0; i < alen - blen; i++) {
            bi <<= 1LL;
            if (a[st1 + i]) {
              mc1++;
              bi |= 1LL;
            }
          }

          for (ll i = 0; i < blen; i++) {
            ll aloc = st1 + i + alen - blen;
            ll bloc = st2 + i;

            bi <<= 1LL;
            if (a[aloc] != a[bloc]) {
              mc2++;
              bi |= 1LL;
            }
          }

          if (bi > mxbi)
            mxbi = bi;
          // if(mxmc <= mc1 + mc2) {
          //     mxmc = mc1 + mc2;
          //     // printf("%d ~ %d, %d ~ %d A%d B%d 1_%d 2_%d\n",
          //     st1,ed1,st2,ed2,alen,blen,mc1,mc2);

          // }
        }

  printAsBin(mxbi);
  cout << "\n";
}

int main() {
  ll t;
  cin >> t;

  // bit단에서 가장 다른게 많은걸 찾는거

  while (t--)
    rmain();
}
