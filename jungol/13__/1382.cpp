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

int typ;
int val;
int p[105];
int cnt[105];
int dp[10005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> val >> typ;
    for(int i = 0;i < typ;i++) cin >> p[i] >> cnt[i];
    dp[0] = 1;
    for(int i = 0;i < typ;i++) {
        int cval = p[i], ccnt = cnt[i];
        
        for(int j = val; j >= 0;j--)
            for(int k = 1; k <= ccnt && j - cval * k >= 0;k++)
                dp[j] += dp[j - cval * k];
    }
    
    cout << dp[val];
}
