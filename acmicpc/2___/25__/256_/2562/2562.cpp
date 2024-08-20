#include <iostream>

using namespace std;

int main() {
	int b = -987654321;
	int b_index = -1;
	for (int i = 0; i < 9; i++) {
		int tp = 0;
		cin >> tp;
		if (tp > b) {
			b = tp;
			b_index = i;
		}
	}
	cout << b << "\n" << b_index + 1;
}