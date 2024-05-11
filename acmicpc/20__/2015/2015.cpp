#include <bits/stdc++.h>

using namespace std;

bool detail = false;

int add[200001];

map<int, long long> m;

int main() {
	ios::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int count_of_thing = 0;
	long long int k = 0; // 맞춰야 되는 값

	long long int now_add = 0;

	long long int ans = 0;

	cin >> count_of_thing >> k;

	for (int i = 0; i < count_of_thing; i++) {
		int tmp = 0;
		cin >> tmp;
		now_add += tmp;
		add[i] = now_add;
	}

	for (int i = 0; i < count_of_thing; i++) {
		if (add[i] == k) ans++;

		ans += m[add[i] - k];

		m[add[i]]++;
	}

	cout << ans;
}