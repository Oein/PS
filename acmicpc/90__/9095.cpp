#include<iostream>

using namespace std;

int memo[11];

int count(int x) {
	if (x <= 0) return 0;
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (x == 3) return 4;
	if (memo[x] != 0)return memo[x];
	memo[x] = count(x - 1) + count(x - 2) + count(x - 3);
	return memo[x];
}

int main() {
	for (int i = 0; i < 11; i++) {
		memo[i] = 0;
	}
	int t;
	int n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << count(n) << '\n';
	}
}