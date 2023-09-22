#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <any>
#include <thread>

using namespace std;

string roll;
string bridge[2];

int dp[3][105][25];

void processIJ(int type, int i, int j) {
    int moded = (type + 1) % 2;
    if(bridge[type][i] == roll[j]) {
        int cnt = 0;
        
        for (int k = 0; k < i; k++)
        {
            cnt += dp[moded][k][j - 1];
            dp[type][i][j] = cnt;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> roll >> bridge[0] >> bridge[1];
    
    for(int i = 0;i < bridge[0].size();i++) {
        if (bridge[0][i] == roll[0])
            dp[0][i][0] = 1;
        if (bridge[1][i] == roll[0])
            dp[1][i][0] = 1;
    }
    
    for(int i = 0;i < bridge[0].size();i++) {
        for(int j = 1;j < roll.size(); j++) {
            processIJ(0, i, j);
            processIJ(1, i, j);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < bridge[0].size(); i++)
    {
        ans += dp[0][i][roll.size() - 1];
        ans += dp[1][i][roll.size() - 1];
    }

    cout << ans;
}
