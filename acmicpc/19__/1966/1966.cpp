#include <bits/stdc++.h>
using namespace std;
void rmain() {
    int n,m;
    cin >> n >> m;
    vector<int> important;
    queue<pair<int, int>> q;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        q.push({i, x});
        important.push_back(x);
    }
    
    sort(important.begin(), important.end());
    int ans = 0;
    while(!q.empty()){
        pair<int, int> qf = q.front(); q.pop();
        if(qf.second < important[important.size() - 1]) {
            q.push(qf);
            continue;
        }
        
        if(qf.first == m) {
            cout << ans + 1 << "\n";
            return;
        }else {
            ans++;
            important.pop_back();
        }
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) rmain();
}