#include <bits/stdc++.h>
using namespace std;

int broken[100010]; // 이어서 몇개가 고장 낫는지

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k, b;
	cin >> n >> k >> b;

	for (int i = 1; i <= b; i++) {
		int j;
		cin >> j;
		broken[j] = 1;
	}

	for (int i = 1; i <= n; i++) {

		broken[i] += broken[i - 1];
	}

	int mkd = 123456789;

	for (int i = 1; i <= n - k + 1; i++) {
		mkd = min(mkd, broken[i + k - 1] - broken[i]);
	}

	cout << mkd;
}