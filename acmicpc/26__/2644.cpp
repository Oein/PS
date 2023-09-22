#include <bits/stdc++.h>

using namespace std;

int parent[101] = { 0, };
vector<int> children[101];
int chon[101] = { 0, }; //각 노드에 대한 촌수

int main() {
	int count_of_people = 0;

	int me = 0;
	int to_calculate = 0;

	int count_of_edge = 0; // 가족 관계 수

	cin >> count_of_people >> me >> to_calculate >> count_of_edge;

	for (int i = 0; i < count_of_edge; i++) {
		int parent_ = 0;
		int child_ = 0;

		cin >> parent_ >> child_;

		parent[child_] = parent_;
		children[parent_].push_back(child_);
	}

	int now = me;
	int now_chon = 0;
	while (now) {
		now_chon++;
		chon[now] = now_chon;
		now = parent[now];
	}

	int now_other = to_calculate;
	int now_chon_other = 0;
	while (now_other) {
		if (chon[now_other] != 0) { // 만나면
			cout << chon[now_other] + now_chon_other - 1;
			exit(0);
		}

		now_chon_other++;
		now_other = parent[now_other];
	}

	cout << -1;
}