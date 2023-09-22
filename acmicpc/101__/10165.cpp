#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> LN; //노선 자료형

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	vector<LN> line;
	int irrA = INT_MAX, irrB = 0;
	for (int i = 0,a,b; i < m; i++) {
		cin >> a >> b;
		if (a > b) {
			irrA = min(irrA, a);
			irrB = max(irrB, b);
		}
		line.push_back({ {a,b},i+1 });
	}

	sort(line.begin(), line.end(), [](LN ln1, LN ln2) {
		if (ln1.first.first == ln2.first.first)
			return ln1.first.second > ln2.first.second;
		else 
			return ln1.first.first < ln2.first.first;
	});

	bool flag[500001] = { 0 }; //flag == 0 이면 출력
	int lastEnd = 0;
	for (int i = 0; i < m; i++) {
		int st = line[i].first.first, en = line[i].first.second;
		int idx = line[i].second;
		if (st > en) continue;

		if (lastEnd >= en) flag[idx] = true;
		else lastEnd = en;

		if (irrA <= st || en <= irrB) flag[idx] = true;
	}

	lastEnd = 0;
	for (int i = 0; i < m; i++) {
		int st = line[i].first.first, en = line[i].first.second;
		int idx = line[i].second;
		if (st < en) continue;
		en += n;
		
		if (lastEnd >= en) flag[idx] = true;
		else lastEnd = en;
	}

	for (int i = 1; i <= m; i++) if (!flag[i]) cout << i << " ";
}