#include <bits/stdc++.h>

using namespace std;

int n, m;
int marbleNum[302];

bool check_(int mid) {
	int cnt = 1;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (sum + marbleNum[i] <= mid) {
			sum += marbleNum[i];
		}
		else {
			if (marbleNum[i] <= mid)
				sum = marbleNum[i];
			else return false;
			cnt++;
		}
	}
	return cnt <= m; // 그룹 수가 적으면 false 넘으면 true
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
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}

	cout << high << "\n";
}