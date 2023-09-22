#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n = 0; // count of numbers
int s = 0; // 최소 조건
int numbers[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	int low = 0;
	int high = 0;
	int len = INT_MAX;
	ll sum = numbers[0];

	while (low <= high && high < n) {
		if (sum < s) {
			high++;
			sum += numbers[high];
		}
		else if (sum == s) {
			len = min(len, (high - low + 1));
			high++;
			sum += numbers[high];
		}
		else { // sum > s
			len = min(len, (high - low + 1));
			sum -= numbers[low];
			low++;
		}
	}

	if (len == INT_MAX) cout << "0";
	else cout << len;
}