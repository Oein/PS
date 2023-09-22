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

const int MAXN = 500,
          MAXM = 124750;
int n , m;

vector<int> paths[MAXN + 5];
bool visited[MAXN + 5];
int startPT = 0;
int howManyCanConnect[MAXN + 5];
void dfs(int now){
    if(now != startPT) {
        // 한번이라도 움직임
        howManyCanConnect[startPT]++;
        howManyCanConnect[now]++;
    }
    for(auto x : paths[now]){
        if(visited[x]) continue;
        visited[x] = 1;
        dfs(x);
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int from , to;
        cin >> from >> to;
        paths[from].push_back(to);
    }

    int ans = 0;

    for(int i = 1;i <= n;i++){
        fill(visited , visited + n + 1 , false);
        visited[i] = 1;
        startPT = i;
        dfs(i);
    }

    for(int i = 1;i <= n;i++){
        if(howManyCanConnect[i] == n - 1){
            ans++;
        }
    }

    cout << ans;
}