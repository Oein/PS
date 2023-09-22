#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int n;
int count_of_yulmae[10005];
vector<int> paths[10005];
int dist[10005];
int max_cnt = 0;
int stp = 0;
queue<int> q;
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> count_of_yulmae[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int c, d;
        cin >> c >> d;
        paths[c].push_back(d);
        paths[d].push_back(c);
    }

    for (int i = n; i >= 1; i--) { // 거꾸로 해야 마지막에 제일 작은 stp가 나옴
        fill(dist, dist + n + 1, -1);
        
        q.push(i);
        dist[i] = count_of_yulmae[i];
        while (!q.empty()) {
            int now = q.front(); q.pop();
            if (dist[now] >= max_cnt) {
                max_cnt = dist[now];
                stp = i;
            }
            for (auto next : paths[now]) {
                if (dist[next] != -1) continue;
                dist[next] = dist[now] + count_of_yulmae[next];
                q.push(next);
            }
        }
    }
    
    cout << max_cnt << " " << stp;
}
