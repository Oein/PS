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
const int MOD = 20100529;

int dp[100005] = {0, 1, 3, };

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 3; i <= n;i++) dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;
    
    cout << dp[n];
}

// 1 : 1
// 2 : 3
// 3 : 5
// 4 : 9
// 5 : 15
// 6 : 25
