#include <bits/stdc++.h>
using namespace std;

int n;
char bueDengHo[9];
bool used[10] = { false, };
string small = "";
string large = "";

bool possible(int a, int b, char c) {
	if (c == '<') return a < b;
	return a > b;
}

void solve(int cnt, string s) {
	if (cnt == n + 1) {
		if (small == "") {
			small = s;
			return;
		}

		large = s;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (used[i]) continue;
		if (cnt == 0 || possible(s[cnt - 1] , i + '0', bueDengHo[cnt - 1])) {
			used[i] = true;
			solve(cnt + 1, s + to_string(i));
			used[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> bueDengHo[i];
	}

	solve(0, "");
	cout << large << '\n' << small;
}