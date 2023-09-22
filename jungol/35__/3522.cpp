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

int n;
const int MOD = 1000000007;

int dp[3] = {1, 1, 2};

void nextFibo() {
    dp[0] = dp[1];
    dp[1] = dp[2];
    dp[2] = (dp[0] + dp[1]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    if(n <= 2) {
        cout << 1;
        return 0;
    }
    
    int nowFibo = 3;
    while (nowFibo < n) {
        nextFibo();
        nowFibo++;
    }
    cout << dp[2];
}
