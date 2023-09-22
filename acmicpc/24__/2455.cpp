#include <iostream>
using namespace std;

int main() {
	int sit[5] = { 0, };
	int stand[5] = { 0, };
	int temp = 0, max = 0;;
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		stand[i] = temp;
		cin >> temp;
		sit[i] = temp;
	}
	temp = 0;
	for (int i = 0; i < 3; i++) {
		temp = temp + sit[i];
		temp = temp - stand[i];
		if (temp > max) max = temp;
	}
	cout << max;
}