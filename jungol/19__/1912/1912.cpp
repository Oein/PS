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

const int MAXN = 100000,
          MAXM = 500000;

vector<int> paths[MAXN + 5];
bool visited[MAXN + 5];

void dfs(int now){
    cout << now << " ";
    for(auto x : paths[now]){
        if(!visited[x]){
            visited[x] = true;
            dfs(x);
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    int n , m;
    cin >> n >> m;

    for(int i = 0;i < m;i++){
        int from , to;
        cin >> from >> to;
        paths[from].push_back(to);
        paths[to].push_back(from);
    }

    for(int i = 1;i <= n;i++){
        sort(paths[i].begin(), paths[i].end());
    }

    visited[1] = 1;
    dfs(1);
}