#include <bits/stdc++.h>

using namespace std;

struct State {
	int num = 0;
	string cmd = "";
};

bool visited[10000];

int main() {
	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {
		memset(visited, false, sizeof(visited));
		int st = 0;
		int ed = 0;
		cin >> st >> ed;

		State state;
		state.cmd = "";
		state.num = st;

		queue<State> q;
		q.push({ st , "" });
		visited[st] = true;
		while (!q.empty()) {
			State now = q.front();
			q.pop();

			if (now.num == ed) {
				cout << now.cmd << "\n";
				break;
			}

			// 계산

			// D
			if (!visited[(now.num * 2) % 10000]) {
				visited[(now.num * 2) % 10000] = true;
				q.push({ (now.num * 2) % 10000 , now.cmd + "D" });
			}


			// S
			int sn = now.num - 1;
			if (sn < 0) sn = 9999;
			if (!visited[sn]) {
				visited[sn] = true;
				q.push({ sn , now.cmd + "S" });
			}

			// L

			if (!visited[(now.num % 1000) * 10 + (now.num / 1000)]) {
				visited[(now.num % 1000) * 10 + (now.num / 1000)] = true;
				q.push({ (now.num % 1000) * 10 + (now.num / 1000) , now.cmd + "L" });
			}
		
			//R

			if (!visited[now.num / 10 + (now.num % 10) * 1000]) {
				visited[now.num / 10 + (now.num % 10) * 1000] = true;
				q.push({ now.num / 10 + (now.num % 10) * 1000 , now.cmd + "R" });
			}
		}
	}
}