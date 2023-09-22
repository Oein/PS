#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;
vector<int> v[MAX];
long long N, d[MAX], ans;
long long ret(long long n) {
	return n * (n - 1) / 2;
}
long long dfs(int cur) {
	d[cur] = 1;
	for (auto i : v[cur]) {
		if (!d[i]) {
			d[cur] += dfs(i);
		}
	}
	ans += ret(N) - ret(N - d[cur]);
	return d[cur];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << ans - ret(N) << "\n";
}
