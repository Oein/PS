#include<iostream>
using namespace std;

int n, m, ans, all_add;
int mem[110], cost[110];
int dp[110][10010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> mem[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        all_add += cost[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= all_add; j++)
        {
            if (j - cost[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + mem[i]);
            
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            
            if(i == n){
                if(dp[i][j] >= m){
                    cout << j << "\n";
                    break;
                }
            }
        }
    }
}
