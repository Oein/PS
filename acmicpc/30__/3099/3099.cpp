#include <bits/stdc++.h>

using namespace std;

string cmd = "";

int memo[10001][28];

int solve(int now, char main_memory) {
	if (now == cmd.size()) return 0; // 더이상 출력 X == 0
	if (memo[now][(int)main_memory - 'A'] != 0) return memo[now][(int)main_memory - 'A'];

	int ans = INT_MAX;
	if (cmd[now] == main_memory) {
		ans = solve(now + 1, main_memory) + 1;			  // write
	}
	else {
		ans = solve(now + 1, main_memory) + 2;			  // use next and write
		ans = min(solve(now + 1, cmd[now]) + 2, ans); // use set  and write
	}

	memo[now][(int)main_memory - 'A'] = ans;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(memo, 0, sizeof(memo));

	cin >> cmd;

	cout << solve(0, cmd[0]) + 1 << "\n";
}