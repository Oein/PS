#include <bits/stdc++.h>

using namespace std;

int by = 0;
int bx = 0;
int sy = 0;
int sx = 0;
int fy = 0;
int fx = 0;
int sd = 0;
int fd = 0;
bool board[110][110];
bool visited[110][110][6];

struct Pos {
	int x;
	int y;
};

struct State
{
	Pos p;
	int d;
	int c;
};

Pos dir[] = { {0 , 0} , {1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1} };

bool iow(Pos d) {
	return d.x >= 1 && d.x <= bx && d.y >= 1 && d.y <= by;
}

int turn_(int n, int m) {
	if (m == 0) {
		// left
		if (n == 1) return 4;
		else if (n == 2) return 3;
		else if (n == 3) return 1;
		else if (n == 4) return 2;
	}
	else {
		// right
		if (n == 1) return 3;
		else if (n == 2) return 4;
		else if (n == 3) return 2;
		else if (n == 4) return 1;
	}
}

int main() {
	cin >> by >> bx;
	for (int i = 1; i <= by; i++) {
		for (int j = 1; j <= bx; j++) {
			cin >> board[i][j];
		}
	}
	cin >> sy >> sx >> sd >> fy >> fx >> fd;

	queue<State> q;
	visited[sy][sx][sd] = 1;

	q.push({ {sx , sy} , sd , 0 });

	while (!q.empty()) {
		State now = q.front();
		q.pop();

		if (now.p.x == fx && now.p.y == fy && now.d == fd) {
			cout << now.c;
			exit(0);
		}

		// go
		for (int i = 1; i <= 3; i++) {
			Pos npos = { now.p.x + (i * dir[now.d].x) , now.p.y + (i * dir[now.d].y) };
			if (!iow(npos)) break;
			if (visited[npos.y][npos.x][now.d]) continue;
			if (board[npos.y][npos.x] == 1) break;

			visited[npos.y][npos.x][now.d] = true;
			q.push({ npos , now.d , now.c + 1 });
		}

		//left
		int nld = turn_(now.d, 0);
		if (!visited[now.p.y][now.p.x][nld]) {
			visited[now.p.y][now.p.x][nld] = true;
			q.push({ now.p , nld , now.c + 1 });
		}

		int rld = turn_(now.d, 1);
		if (!visited[now.p.y][now.p.x][rld]) {
			visited[now.p.y][now.p.x][rld] = true;
			q.push({ now.p , rld , now.c + 1 });
		}
	}
}