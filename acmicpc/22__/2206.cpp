#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX 1000

typedef struct {
    int y, x;
}Dir;

Dir dxdy[4] = { {1,0},{0,1},{-1,0},{0,-1} };

int N, M;
char graph[MAX + 1][MAX + 1];
int visit[MAX + 1][MAX + 1][2];

bool valid(int _ny, int _nx) {
    return (_ny >= 1 && _ny <= N && _nx >= 1 && _nx <= M);
}

int solve() {
    queue<pair<pair<int, int>, int > > q;
    q.push({ {1,1} , 1 });
    visit[1][1][1] = 1;

    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;
        q.pop();


        if (y == N && x == M) {
            return visit[y][x][block];
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dxdy[i].y;
            int nx = x + dxdy[i].x;


            if (valid(ny, nx)) {

                if (graph[ny][nx] == '1' && block) {
                    visit[ny][nx][block - 1] = visit[y][x][block] + 1;
                    q.push({ { ny,nx }, block - 1 });
                }

                if (graph[ny][nx] == '0' && visit[ny][nx][block] == 0) {
                    visit[ny][nx][block] = visit[y][x][block] + 1;
                    q.push({ { ny,nx }, block });
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> graph[i][j];
        }
    }

    cout << solve();
    return 0;
}
