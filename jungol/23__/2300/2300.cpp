#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& c : v)
		cin >> c;

	sort(v.begin(), v.end());

	int i = 0, j = n - 1;
	int min_diff = INT_MAX;
	int p1=-1, p2=-1;

	while (i < j) {
		int sum = v[i] + v[j];
		if (min_diff > abs(sum)) {
			min_diff = abs(sum);
			p1 = v[i], p2 = v[j];
		}

		if (sum == 0)
			break;
		else if (sum > 0)
			--j;
		else
			++i;
	}

	cout << p1 << ' ' << p2 << '\n';

	return 0;
}
