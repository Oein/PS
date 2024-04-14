#include<iostream>
using namespace std;

int main() {
	int money = 0;	// 낼 돈.
	cin >> money;
	money = 1000 - money;	// 거스름돈.


	int coin[6] = { 500, 100, 50, 10, 5, 1 };
	int count[6] = { 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < 6; i++) {
		count[i] = money / coin[i];
		money -= count[i] * coin[i];
	}

	int jandon = 0;
	for (int i = 0; i < 6; i++) {
		jandon += count[i];
	}
	cout << jandon;
}