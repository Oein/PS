#include<iostream>
using namespace std;

int N, M, ans, all_add;
int mem[110], cost[110];
int dp[110][10010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> mem[i];
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
        all_add += cost[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= all_add; j++)
        {
            if (j - cost[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + mem[i]);
            
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    for (int i = 0; i <= all_add; i++)
    {
        if (dp[N][i] >= M)
        {
            cout << i << "\n";
            break;
        }
    }
}
