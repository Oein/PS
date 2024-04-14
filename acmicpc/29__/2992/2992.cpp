#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x;
vector<int> v; // 숫자들
vector<int> maked_number;
vector<bool> is_used; // idx로 숫자 구별
bool done;

int vector_to_int(const vector<int>& vec) {
	int result = 0;
	for (auto num : vec) {
		result = result * 10 + num;
	}
	return result;
}

void get(int cnt) {
	if (cnt == v.size()) {

		int tmpans = vector_to_int(maked_number);
		if ((tmpans > x) && !done) {
			done = true; // 빨리 끝내게
			cout << tmpans;
		}

		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!is_used[i]) {

			is_used[i] = true;
			maked_number.push_back(v[i]);

			get(cnt + 1);

			if (done) return;

			is_used[i] = false;
			maked_number.pop_back();
		}
	}

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> x;
	int tmp = x;

	while (tmp) {
		v.push_back(tmp % 10);
		tmp /= 10;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)	is_used.push_back(false); // 숫자별로

	get(0);
	if (!done) cout << 0; // 안될때
}