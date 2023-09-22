#include<iostream>
#include <algorithm>

using namespace std;

int count(int x) {
	if (x == 1)return 0;
	if (x == 2)return 1;

	int sub3 = x % 3;
	int sub2 = x % 2;
	int select3 = count((x - sub3) / 3) + 1 + sub3;
	int select2 = count((x - sub2) / 2) + 1 + sub2;
	return min(select2, select3);
}

int main() {
	int n;
		cin >> n;
		cout << count(n);
}