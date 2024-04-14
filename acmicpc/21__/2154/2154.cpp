#include <bits/stdc++.h>

using namespace std;

int main() {
	int n = 0;
	cin >> n;

	string nums = "";
	string num = to_string(n);
	int size_of_number = num.size();

	//1234567891011121314151617181920212223

	for (int i = 1; i <= n; i++) {
		nums += to_string(i);
	}

	for (int i = 0; i <= nums.size() - size_of_number; i++) {
		bool ok = true;
		for (int j = 0; j < size_of_number; j++) {
			if (nums[i + j] != num[j]) ok = false;
		}

		if (ok) {
			cout << i + 1;
			exit(0);
		}
	}
}