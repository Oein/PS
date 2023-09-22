#include <iostream>

using namespace std;

void solve(int n, int k, int len) {
	int new_len = len * 2 + k + 3;
	// 개수
	if (n <= 3) {
		if (n == 1) cout << "m";
		else cout << "o";
		exit(0);
	}
	if (new_len < n) {
		solve(n, k + 1, new_len);
	}
	else {
		if (n > len && n <= len + k + 3) {
			if (n - len != 1) {
				cout << "o";
			}
			else {
				cout << "m";
			}
			exit(0);
		}
		else {
			solve(n - (len + k + 3), 1, 3);
		}
	}
}

int main() {
	int n = 0;
	cin >> n;
	solve(n , 1 , 3);
}