#include <bits/stdc++.h>

using namespace std;

int lowest[20002];

struct Node
{
	int v;
	int dist;

	bool operator < (const Node& a) const {
		return this->dist > a.dist;
	}
};

vector<Node> adj[20002];
int sp = 0; // starting point

void find_lowest() {
	// 자신의 위치
	priority_queue<Node> q;
	lowest[sp] = 0;
	q.push({ sp  , 0 });

	while (!q.empty()) {
		Node now = q.top();
		q.pop();
		if (now.dist > lowest[now.v]) continue;
		for (auto p : adj[now.v])
		{
			if (lowest[p.v] > p.dist + now.dist) {
				lowest[p.v] = p.dist + now.dist;
				q.push({ p.v , p.dist + now.dist });
			}
		}
	}
}

int main(void) {
	// priority_queue
	int v = 0; // 점 개수
	int e = 0; // 선 개수

	cin >> v >> e;

	cin >> sp;

	for (int i = 1; i <= v; i++) {
		lowest[i] = INT_MAX;
	}

	for (int i = 0; i < e; i++) {
		int st = 0;
		int ed = 0;
		int w = 0; // weight
		cin >> st >> ed >> w;

		adj[st].push_back({ ed, w });
	}

	find_lowest();

	for (int i = 1; i <= v; i++) {
		if (lowest[i] == INT_MAX) cout << "INF\n";
		else cout << lowest[i] << "\n";
	}
}