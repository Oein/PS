#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<pair<int , int> , pair<int , int>> ppiipii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> msi;
typedef map<string , string> mss;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

// 가로 , 세로 , 가로 나누기 , 세로 나누기
int n, m, r, s;
// 걸리는 시간
int board[20][20];
// 그냥 dp
int dp[20][20];
// y_max[? 번째 가로줄][세로]
// 대충 pre sum 같은거임
int y_max[20][20];

int max_sum[20][20];

int getDp(int bit){
    memset(y_max,0,sizeof(y_max));
    memset(max_sum , 0 , sizeof(max_sum));
    int now_x_line = 0;

    for (int i=0; i<n; i++) {
        for (int j=1; j<=m; j++) {
            y_max[now_x_line][j] += board[i][j];
        }
        if(bit & (1 << i)) now_x_line++;
    }

    for (int i=0; i<=now_x_line; i++) {
        for (int j=1; j<=m; j++) {
            y_max[i][j] += y_max[i][j-1];
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = i;j <= m; j++){
            int ans_ = 0;

            for(int k = 0;k <= now_x_line;k++){
                ans_ = max(ans_ , y_max[k][j] - y_max[k][i -  1]);
            }

            max_sum[i][j] = ans_;
        }
    }

    for(int i = 1;i <= m;i++){
        dp[0][i] = max_sum[1][i];
    }

    for(int i = 1;i <= s;i++){
        for(int j = i;j <= m;j++){
            dp[i][j] = max_sum[1][j]; // 가장 큰거

            for(int k = i - 1;k < j;k++){
                dp[i][j] = min(dp[i][j] , max(dp[i - 1][k] , max_sum[k + 1][j]));
            }
        }
    }

    // dp?
    return dp[s][m];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> r >> s;
    for(int i = 0;i < n;i++){
        for(int j = 1;j <= m;j++){ // solve 에서 y - 1 써야됨
            cin >> board[i][j];
        }
    }

    int ans = 1000000000;

    for (int i=0; i < (1 << (n - 1)); i++) {
        int c = 0;
        for (int j=0; j < n - 1; j++) {
            if(i & (1 << j)) c++;
        }
        if(c == r){ // 가로 나누는 수가 같음
            ans = min(ans,getDp(i));
        }
    }

    cout << ans;
}