#include <bits/stdc++.h>
using namespace std;

// 맵 길이 , 곰 움직일수 있는 칸수 , 곰돌이 x , 곰돌이 y , 집 x , 집 y
int n, m, sx, sy, ex, ey;
int dist[800][800], dist2[800][800];
string board[800];
queue<pair<int, int>> Q;

// out of bound? 이건가
bool OOB(int x , int y){
    return x < 0 || x >= n || y < 0 || y >= n;
}

int main() {
	memset(dist, -1, sizeof dist);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < n; j++) { // 입력 se , ex로 중요 위치
			if (board[i][j] == 'M') sx = i, sy = j;
			if (board[i][j] == 'D') ex = i, ey = j;
			if (board[i][j] != 'H') continue;
			dist[i][j] = 0; 
            Q.push({ i, j });
            // 벌집 위치 등록
		}
	}

	while (Q.size()) { // 벌집
		auto [x, y] = Q.front(); //auto로 Q에 있는 x , y 구하기
        Q.pop();
		for (int k = 0; k < 4; k++) { // 4방향 전부다
			int nx = x + "1012"[k] - '1';
			int ny = y + "2101"[k] - '1';
            // 갈수 없는곳이나 , 밖에 나갈경우 continue
			if (OOB(nx, ny) || board[nx][ny] != 'G' && board[nx][ny] != 'M') continue;
			if (dist[nx][ny] != -1) continue; // 벌집이면 -1
			dist[nx][ny] = dist[x][y] + 1; // 몇턴 만에 벌이 가는지
            Q.push({ nx, ny }); // 다음 벌 유포 장소 추가
		}
	}

	auto Check = [&](int mid) -> bool { // 대충 BFS 푸는 함수
		if (dist[sx][sy] <= mid) return 0;
		memset(dist2, -1, sizeof dist2);
		dist2[sx][sy] = mid; Q.push({ sx, sy });
		for (int cnt = 1; Q.size(); cnt++) {
			for (int ww = 0; ww < m; ww++) { // m보다 작을때 (한 턴)
				for (int i = Q.size(); i --> 0;) {
					auto [x, y] = Q.front(); Q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + "1012"[k] - '1'; // dx 를 1012
						int ny = y + "2101"[k] - '1'; // dy 를 2101
						if (OOB(nx, ny) || dist2[nx][ny] != -1) continue; // 박으로 나가면
						if (board[nx][ny] == 'T') continue;
                        if (dist[nx][ny] != -1 && dist[nx][ny] < mid + cnt) continue;
						dist2[nx][ny] = mid + cnt; Q.push({ nx, ny });
					}
				}
			}
			for (int i = Q.size(); i --> 0;) {
				auto [x, y] = Q.front(); Q.pop();
				if (dist[x][y] <= dist2[x][y]) continue;
				Q.push({ x, y });
			}
		}
		return dist2[ex][ey] != -1;
	};

	int lo = -1, hi = 1000000; // low , high
	while (lo + 1 < hi) { // 1 전까지
		int mid = lo + hi >> 1;
		if (Check(mid)) lo = mid; // 체크 해 가면서 하는거
		else hi = mid;
	}
	cout << lo << '\n';
}