#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int board[101][101];
long long int dp[101][101] = { 0, };

int main() {
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	dp[0][0] = 1;
	
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (board[y][x] == 0) continue;
			// cout << "Now : (" << x << " , " << y << ")\n";
			// 오른쪽
			if (x + board[y][x] < n) { // 안에 있을떄
				dp[y][x + board[y][x]] += dp[y][x];

				// cout << "dp[" << y << "] [ " << x + board[y][x] << "] : " << dp[y][x + board[y][x]] << "\n";
			}

			// 아래
			if (y + board[y][x] < n) { // 안에 있을떄
				dp[y + board[y][x]][x] += dp[y][x];
				// cout << "dp[" << y + board[y][x] << "] [ " << x << "] : " << dp[y + board[y][x]][x] << "\n";
			}
		}
	}

	cout << dp[n - 1][n - 1];
}