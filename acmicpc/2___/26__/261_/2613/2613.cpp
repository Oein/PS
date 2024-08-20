#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int n, m;
int marbleNum[302];

bool check_(int mid) {
	int cnt = 1;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (sum + marbleNum[i] <= mid) { // 그룹 더한게 최대값보다 작으면
			sum += marbleNum[i]; // 한게 더 그룹에 추가
		}
		else { // 아니면
			if (marbleNum[i] <= mid)  // 지금 구슬이 다 더한것 보다 작으면
				sum = marbleNum[i]; // new group
			else return false; // 아니면 못함.
			cnt++; // 그룹수 추가
		}
	}
	return (cnt <= m); // 그룹 수가 적으면 false 넘으면 true
}

vector<int> ans;

void print_ans(int ma) {
	int cnt = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (sum + marbleNum[i] <= ma) {
			cnt++;
			sum += marbleNum[i];
		}
		else {
			ans.push_back(cnt);
			sum = marbleNum[i];
			cnt = 1;
		}
	}

	ans.push_back(cnt);

	// 아 최대값으로만 하니까 m 에 안맞게 나올때도 있네
	while (ans.size() < m) {
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] > 1) {
				int nans = ans[i] / 2;
				int nians = ans[i] - nans;
				ans[i] = nans;
				ans.insert(ans.begin() + i + 1, nians);
				break;
			}
		}
	}
	assert(!(ans.size() < m));

	for (int x : ans) {
		cout << x << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> marbleNum[i];
	}

	int low = 1;
	int high = 30000;

	while (low < high)
	{
		int mid = (low + high) / 2; // 각 그룹의 합 중 최댓값이 최소가 되도록 M개의 그룹으로 나누었을 때 그 최댓값
		if (check_(mid)) {
			high = mid; //넘었으니까
		}
		else {
			low = mid + 1;
		}
	}

	cout << high << "\n";

	print_ans(high);
}