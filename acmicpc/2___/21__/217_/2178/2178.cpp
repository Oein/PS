#include <bits/stdc++.h>

using namespace std;

int N, M;                                // new X , Y만들때 배열 overfollow나지 말라고
int check[100][100] = { 0, };  //값(거리)

bool is_visited[100][100] = { false, };    //갓는지 않갓는지

string arr[100];          //지도


void bfs() {
    int dx[4] = { 0, 1, 0, -1};     // i로 new X와 new Y를 만들기 위한 배열
    int dy[4] = { -1, 0, 1, 0};     // x + dx[i] , y + dy[i] 쓰면 new X , Y 나옴
    
    is_visited[0][0] = true;     // 0,0갓다고 표시
    
    queue<pair<int, int> > q;      //한번쓰고 버릴꺼
    q.push(make_pair(0,0));     //좌표큐에 넣기

    while(!q.empty()) {
        int x = q.front().second;  // Now X
        int y = q.front().first;      // Now Y

        q.pop();                               //현재 좌표 제거 (새로운 좌표를 넣을거임)

        for (int i = 0; i < 4; i++) {      //네 방향으로
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (0 <= newX &&   //x가 0보다 작지 않게
                newX < M &&     //x가 촤대x보다 크지않게
                0 <= newY &&   //y가 0보다 작지 않게
                newY < N &&    //y가 최대y 보다 크지 않게
                arr[newY][newX] == '1' &&  //지도에서 갈수있는지
                !is_visited[newY][newX] &&   //간적이 있는지
                check[newY][newX] == 0  //거리가 0인지
            ) {
                check[newY][newX] = check[y][x] + 1; //거리기록
                is_visited[newY][newX] = true; //갓다고 기록
                q.push(make_pair(newY, newX)); //좌표 큐에 등록
            }
        }
    }

}

int main() {

    int i;

    cin >> N >> M;
    for (i = 0; i < N; i++) cin >> arr[i];

    bfs();
    cout << check[N-1][M-1]+1 << "\n";

    return 0;
}
