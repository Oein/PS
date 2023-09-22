#include <iostream>
#include <queue>

using namespace std;

int finder = 0;
int hider = 0;

bool visit[100010] = { 0, };
queue<int> place_to_go;
queue<int> times_that_i_need;

/*

경우의 수

앞으로 1칸
뒤로 1칸
앞으로 x2 칸

*/

bool can_go(int place) {
	if (place <= 100000 && place >= 0) {
		if (visit[place] == false) { // ????
			return true;
		}
	}
	return false;
}

void solve() {
	visit[place_to_go.front()] = true;
	while (!place_to_go.empty()) {
		if (place_to_go.front() == hider) {
			cout << times_that_i_need.front();
			break;
		}
		
		int now = place_to_go.front();
		int used = times_that_i_need.front();
		place_to_go.pop();
		times_that_i_need.pop();

		if (can_go(now - 1)) {
			place_to_go.push(now - 1);
			times_that_i_need.push(used + 1);
			visit[now - 1] = true;
		}
		if (can_go(now + 1)) {
			place_to_go.push(now + 1);
			times_that_i_need.push(used + 1);
			visit[now + 1] = true;
		}
		if (can_go(now * 2)) {
			place_to_go.push(now * 2);
			times_that_i_need.push(used + 1);
			visit[now * 2] = true;
		}
	}
}

int main() {
	cin >> finder >> hider;

	place_to_go.push(finder);
	times_that_i_need.push(0);
	visit[finder] = true;

	solve();
}