#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, m, h, hole[1004][1004][4], height[1004][1004], ret, a;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void enqueue(int y, int x, int h){
    if(height[y][x] > h){
        height[y][x] = h;
        pq.push({h, 1004 * y + x});
    }
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> h;
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= m; j++){
            cin >> a;
            hole[i - 1][j][2] = a;
            hole[i][j][0] = a;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m + 1; j++){
            cin >> a;
            hole[i][j - 1][1] = a;
            hole[i][j][3] = a;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            height[i][j] = h;
        }
    }
    // 가장자리에 있는 hole을 통해 최소값을 잡는다.
    for(int i = 0; i <= n + 1; i++){
        //가장 왼쪽, 오른쪽 확인
        if(hole[i][0][1] != -1) enqueue(i, 1, hole[i][0][1]);
        if(hole[i][m + 1][3] != -1) enqueue(i, m, hole[i][m + 1][3]);
    }

    for(int i = 0; i <= m + 1; i++){
        //가장 위쪽, 아래쪽 확인
        if(hole[0][i][2] != -1) enqueue(1, i, hole[0][i][2]);
        if(hole[n + 1][i][0] != -1) enqueue(n, i, hole[n + 1][i][0]);
    }

    while(pq.size()){
        int y = pq.top().second / 1004;
        int x = pq.top().second % 1004;
        int here_height = pq.top().first;
        pq.pop();
        if(height[y][x] != here_height) continue;
        for(int i = 0; i < 4; i++){
            if(hole[y][x][i] == -1) continue;
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 1 || ny > n || nx < 1 || nx > m) continue;
            int next_height = max(height[y][x], min(hole[y][x][i], height[ny][nx]));
            if(height[ny][nx] > next_height){
                height[ny][nx] = next_height;
                pq.push({next_height, 1004 * ny + nx});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ret += height[i][j];
        }
    }
    cout << ret << '\n';

    return 0;
}