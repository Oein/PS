#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int num[2001];
	for (int i = 0; i < 2001; i++) {
		num[i] = 0;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input = 0;
		cin >> input;
		num[input + 1000]++;
	}
	for (int i = 0; i < 2001; i++) {
		if (num[i] > 0)cout << i-1000 << " ";
	}
}