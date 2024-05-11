#include <iostream>

using namespace std;

int main() {
	int n = 0;
	int s = 987654321;
	int b = -987654321;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tp = 0;
		cin >> tp;
		if (tp < s) s = tp;
		if (tp > b) b = tp;
	}

	cout << s << " " << b;
}