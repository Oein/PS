#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int board[100][100];
bool visited[100][100];
bool air[100][100];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {

    int cnt = 0;
    int ans = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            visited[i][j] = false;
            air[i][j] = true;

            if (board[i][j] == 1) cnt++;
        }
    }

    int hour = 0;

    while(cnt > 0) {
        hour++;
        // 0, 0에서 bfs를 통해 공기가 찬 곳을 모두 air -> false로 바꾼다
        queue<pii > q;
        q.push({0, 0});
        visited[0][0] = true;
        air[0][0] = false;

        while(!q.empty()) {
            pii now = q.front();
            int y = now.first;
            int x = now.second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];

                if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && board[ny][nx] == 0) {
                    visited[ny][nx] = true;
                    air[ny][nx] = false;
                    q.push({ny, nx});
                }
            }
        }

        vector<pii > outside;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
                if (board[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int nexty = i + dy[k];
                        int nextx = j + dx[k];

                        if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < m && !air[nexty][nextx]) {
                            outside.push_back({i, j});
                            break;
                        }
                    }
                }
            }
        }

        int removeThingsMAXIDX = outside.size();
        for (int r = 0; r < removeThingsMAXIDX; r++) {
            int y = outside[r].first;
            int x = outside[r].second;
            air[y][x] = false;
            board[y][x] = 0;
        }

        if (cnt - removeThingsMAXIDX == 0) {
            ans = removeThingsMAXIDX;
        }
        cnt -= removeThingsMAXIDX;
    }


    cout << hour << "\n" << ans;
    return 0;
}