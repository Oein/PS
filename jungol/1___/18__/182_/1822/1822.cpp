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

int a, b, d, n, ans = 1, sum;
const int MOD = 1000;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> d >> n;
    vector<int> memo(n + 5);
    memo[0] = 1;
    
    for(int i = 1;i <= n;i++) {
        if(i >= b) {
            sum -= memo[i - b];
            
            sum += 1000;
            sum %= MOD;
        }
        if(i >= a) {
            sum += memo[i - a];
            
            sum += 1000;
            sum %= MOD;
        }
        memo[i] = sum;
        ans += memo[i];
        if(i >= d) {
            ans -= memo[i - d];
            
            sum += 1000;
            sum %= MOD;
        }
    }
    
    cout << ans % MOD;
}
