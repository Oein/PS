#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	vector<int> num;
	cin >> n;
	
	int j;
	for (int i = 0; i < n; i++) {
		cin >> j;
		num.push_back(j);
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < n; i++) {
		cout << num[i] << '\n';
	}
}