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
using namespace std;
using ll = long long;

int dp[1005][1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a;
    string b;
    cin >> a >> b;
    
    for(int i = 1;i <= a.size();i++)
        for(int j = 1;j <= b.size();j++)
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        
    
    cout << dp[a.size()][b.size()];
}
