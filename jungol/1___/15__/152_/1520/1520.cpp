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

int steps[305];
int dp[305];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> steps[i];
    
    dp[1] = steps[1];
    dp[2] = steps[1] + steps[2];
    dp[3] = max(dp[1] + steps[3], steps[2] + steps[3]);
    
    for(int i = 4; i <= n;i++) {
        dp[i] = max(
                    dp[i - 2] + steps[i],
                    dp[i - 3] + steps[i - 1] + steps[i]
                    );
    }
    
    cout << dp[n];
}
