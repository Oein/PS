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

int n; // 직원들 수

vector<int> paths[5005];
int visited[5005];
int nowVis = 1;

int work = 0;

ll bfs(int st){
    long long cost = 0;
    int finded = 1;

    queue<pii> q;
    q.push({st , 1});
    visited[st] = nowVis;

    while (!q.empty())
    {
        pii now = q.front();
        q.pop();
        cost += (ll)now.second;

        for (auto next: paths[now.first])
        {
            if (visited[next] == nowVis) {
                continue;
            }
            visited[next] = nowVis;
            finded++;
            q.push({next , now.second + 1});
        }
    }

    nowVis++;
    
    if(finded != n) {
        return LONG_LONG_MAX;
    }
    return cost;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i = 1;i <= n;i++){
        int m;
        cin >> m;
        while(m--){
            int upper;
            cin >> upper;
            paths[upper].push_back(i);
        }
    }

    ll ans = LONG_LONG_MAX;
    for(int i = 1;i <= n;i++){
        ll bf = bfs(i);
        if(bf < ans){
            ans = bf;
            work = i;
        }
    }
    cout << ans;
}