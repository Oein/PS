#include <vector>
#include <iostream>
#include <queue>
struct QData {
    int loc;
};
using namespace std;
int n;
vector<int> path[10005];
bool visited[10005];
int main() {
    cin >> n;
    for(int i = 0;i < n - 1;i++) {
        int par, chi;
        cin >> par >> chi;
        path[chi].push_back(par);
        visited[i] = false;
    }
    
    int node1;
    int node2;
    visited[n - 1] = false;
    visited[n] = false;
    cin >> node1 >> node2;
    
    queue<QData> q;
    
    q.push({
        node1
    });
    q.push({
        node2
    });
    
    while(!q.empty()) {
        QData qf = q.front();
        q.pop();
        
        if(visited[qf.loc]) {
            cout << qf.loc << "\n";
            break;
        }
        
        visited[qf.loc] = 1;
        
        for(auto x : path[qf.loc]) {
            q.push({
                x
            });
        }
    }
}
