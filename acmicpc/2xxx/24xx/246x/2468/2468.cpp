#include <iostream>
#include <string.h>
using namespace std;

int N = 0, maxN = 0;                   //N = 사이즈 , maxN = a
int height[101][101] = {{0 ,},};  //높이 정보
int visit[101][101] = {{0 ,},};      //DFS로 갔는지
int dy[4] = { 0, 0, +1, -1 };         //i 로 +- x
int dx[4] = { +1, -1, 0, 0 };         //i 로 +- y
int answer = 1;                           //출력할 답

void dfs(int y, int x, int w) {
    visit[y][x] = 1; //거기에 갔다고
    for (int i = 0; i < 4; i++) { //i +- x , y
        int ny = y + dy[i];  //newX
        int nx = x + dx[i];  //newY
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;  //맵밖에 있는지
        if (visit[ny][nx] || height[ny][nx] <= w) continue;  //갔던곳 인지
        dfs(ny, nx, w);  //실행
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for (int y = 0; y < N; y++) { //높이정보 입력
        for (int x = 0; x < N; x++) {
            cin >> height[y][x];
            if (height[y][x] > maxN) maxN = height[y][x];
        }
    }
    
    for (int w = 1; w < maxN; w++) { //1부터 최대 높이까지
        int overHeightThanRainPlaceCount = 0;
        memset(visit, 0, sizeof(visit));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (height[y][x] > w && !visit[y][x]) {
                    overHeightThanRainPlaceCount += 1;
                    dfs(y, x, w);
                } else visit[y][x] = 1;
            }
        }
        if (overHeightThanRainPlaceCount > answer){
            answer = overHeightThanRainPlaceCount;
        }
    }
    cout << answer;
}
