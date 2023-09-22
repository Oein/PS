#include<iostream>
#include<utility> // algorithem은 크잖어
#include<cstring> // 대충 bits/stdc++.h 없다는뜻
#include<queue>

#define Y first
#define X second

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m; //행 열
int map[305][305]; //기존 맵
int cmap[305][305]; //복사된 맵
bool vst[305][305]; //방문 표시

int zeroCnt(int y, int x) { //좌표 주위에 0의 개수를 구함
    int cnt = 0;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (map[ny][nx] == 0) {
            cnt++;
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int year = 0;

    while (1) { //1년씩 계속 녹임
        int area = 0;
        memset(vst, false, sizeof(vst));
        memset(cmap, 0, sizeof(cmap));
        queue<pair<int, int>> q;
        //bfs
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0 || vst[i][j]) continue;
                q.push({ i,j });
                vst[i][j] = 1;
                area++;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    cmap[cur.Y][cur.X] = map[cur.Y][cur.X] - zeroCnt(cur.Y, cur.X);
                    if (cmap[cur.Y][cur.X] < 0) cmap[cur.Y][cur.X] = 0;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                        if (map[ny][nx] == 0 || vst[ny][nx]) continue;
                        vst[ny][nx] = 1;
                        q.push({ ny,nx });
                    }
                }
            }
        }

        if (area >= 2) { cout << year << '\n'; break; } //while문 탈출
        if (area == 0) { cout << 0 << '\n'; break; } //분리되지 않은 경우



        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i][j] = cmap[i][j];
            }
        }


        year++;
    }

}