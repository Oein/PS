#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n = 0;
int m = 0;
int middle = 0;

int cnt = 0; //이동 cnt
int rcnt = 0;// 이동 cnt (뒤로)

vector<int> v[101]; //똑바로
vector<int> r[101]; //뒤로

bool check[101]; // 갔는지
bool rcheck[101];// 갔는지 (뒤로)

int result_of_balls = 0;

void solve(int node) {
	check[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!check[next]) { // 다음에 할거 안갔으면
			cnt++;
			solve(next);
		}
	}
}

void rsolve(int node) {
	rcheck[node] = true;
	for (int i = 0; i < r[node].size(); i++) {
		int next = r[node][i];
		if (!rcheck[next]) { // 다음에 할거 안갔으면
			rcnt++;
			rsolve(next);
		}
	}
}

void reset() {
	for (int i = 1; i <= n; i++) {
		check[i] = false;
		rcheck[i] = false;
	}
	cnt = 0;
	rcnt = 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int heavy = 0;
		int light = 0;
		cin >> heavy >> light;
		v[heavy].push_back(light);
		r[light].push_back(heavy);
	}

	middle = (n + 1) / 2;

	for (int i = 1; i <= n; i++) {
		reset();
		solve(i);
		rsolve(i);

		if (cnt >= middle || rcnt >= middle) {
			result_of_balls++;
		}
	}

	cout << result_of_balls;
}