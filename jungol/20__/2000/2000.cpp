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

int coin[15];
int dp[64005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, w;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> coin[i];
    cin >> w;
    
    dp[0] = 0;
    for(int i = 1; i <= w; i++) {
        dp[i] = INT_MAX;
        
        for(int j = 0;j < n;j++) {
            if(i < coin[j]) continue;
            if(dp[i - coin[j]] != INT_MAX) dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
    }
    
    if(dp[w] == INT_MAX) {
        cout << "impossible";
        return 0;
    }
    cout << dp[w];
}
