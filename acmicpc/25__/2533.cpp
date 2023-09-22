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
typedef pair<int , int> pi_i;
typedef pair<pair<int , int> , pair<int , int>> ppi_i__pi_i;
typedef pair<long long , long long> pll_ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> ms_i;
typedef map<string , string> ms_s;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

#define MAXN 1000005

int n;
vi edges[MAXN];
int dp[MAXN][2];
// [?][0] = 얼리 0
// [?][1] = 얼리 X
bool visited[MAXN];

void dfs_(int now){
    visited[now] = true;

    dp[now][1] = 0;
    dp[now][0] = 1;

    for(int i = 0;i < edges[now].size();i++){
        int next = edges[now][i];
        if(visited[next]){
            continue;
        }

        dfs_(next);

        dp[now][0] += min(dp[next][0], dp[next][1]); // 내가 얼리면 친구는 상관 ㄴ
        dp[now][1] += dp[next][0]; // 내가 얼리 아니면 친구는 무조건 얼리
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n - 1;i++){
        int u , v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs_(1);

    cout << min(dp[1][0] , dp[1][1]);
}