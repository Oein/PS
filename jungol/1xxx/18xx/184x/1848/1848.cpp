#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include <limits>
#include <string>
#include <cmath>
#include <stack>
#include <climits>
#include <queue>
using namespace std;
using ll = long long;

int n, m;
bool isPinned[45];


int fibo[45] = {1, 1, 2};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 3; i <= 40;i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
    for(int i = 0;i < m;i++) {
        int x;
        cin >> x;
        isPinned[x] = 1;
    }
    long long ans = 1;
    int inc = 0;
    for(int i = 1; i <= n;i++) {
        // cout << i << " / ";
        if(!isPinned[i]) {
            inc++;
            // cout << "INC " << inc << "\n";
            continue;
        }
        // cout << "MULTI " << fibo[inc] << "\n";
        ans *= fibo[inc];
        inc = 0;
    }
    if(inc) ans *= fibo[inc];
    cout << ans;
}
