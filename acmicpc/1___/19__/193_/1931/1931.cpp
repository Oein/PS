#include <bits/stdc++.h>

using namespace std;

struct Meet {
	int st;
	int ed;
};

bool sort_func(Meet a, Meet b) {
	if (a.ed == b.ed) {
		return a.st < b.st;
	}
	else {
		return a.ed < b.ed;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n = 0;
	cin >> n;
	vector<Meet> meets;

	for (int i = 0; i < n; i++) {
		Meet a;
		cin >> a.st >> a.ed;
		meets.push_back(a);
	}

	sort(meets.begin(), meets.end(), sort_func);

	int le = -1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		Meet now = meets[i];
		if (now.st >= le) {
			le = now.ed;
			ans++;
		}
	}

	cout << ans;
}