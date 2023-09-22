#include <bits/stdc++.h>
using namespace std;

int d[100001]; // 숫자
int pare[100001]; // 전 숫자 idx
map<int, int> valToIdx; // 그 숫자가 가진 idx
stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	int k;

	cin >> n >> k;

	vector<vector<int>> adj(n + 1);

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		d[i] = 0;
		for (int j = 0; j < k; j++) {
			d[i] <<= 1;
			d[i] |= (s[j] - '0');
		}
		valToIdx[d[i]] = i;
	}

	// 하밍 숫자 찾기
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			int tmpx = d[i] ^ (1 << j);

			auto it = valToIdx.find(tmpx);

			if (it != valToIdx.end()) {
				adj[i].push_back(it->second);
			}
		}
	}

	memset(pare, -1, sizeof(pare));

	queue<int> q;
	pare[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u]) {
			if (pare[v] == -1) { // 부모 가 없으면
				pare[v] = u; // 내가 부모임
				q.push(v);
			}
		}
	}

	int m;
	cin >> m;

	while (m--) {
		int to;
		cin >> to;
		if (pare[to] == -1) {
			cout << "-1\n";
			continue;
		}

		for (int i = to; i != 1; i = pare[i])
			st.push(i);

		cout << "1 ";
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}

		cout << "\n";
	}
}