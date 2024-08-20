#include <bits/stdc++.h>

using namespace std;

int water_height[301][301];
bool visited[301][301];

struct Pos {
	int y;
	int x;
	int water_height;
	bool operator < (const Pos& a) const
	{
		return water_height > a.water_height;
	}
};

int dx[] = { 1 , -1 , 0 , 0 };
int dy[] = { 0 , 0 , 1 , -1 };

int main() {
	cin.tie(0); 
	cout.tie(0); 
	ios_base::sync_with_stdio(false);

	int n = 0;
	int m = 0;
	cin >> m >> n;
	
	priority_queue<Pos> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> water_height[i][j];
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
			{
				visited[i][j] = true;
				pq.push({ i, j, water_height[i][j] });
			}
				
		}
	}

	int ans = 0;

	while (!pq.empty()) {
		Pos now = pq.top();
		pq.pop();

		ans += now.water_height - water_height[now.y][now.x];

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + now.x;
			int ny = dy[i] + now.y;

			if (nx < 0 || nx >= m || ny <= 0 || ny >= n) continue;

			if (!visited[ny][nx]) {
				int h = max(water_height[ny][nx], now.water_height);
				visited[ny][nx] = true;
				pq.push({ny , nx , h});
			}
		}
	}

	cout << ans << "\n";
}