#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int b = 2000, g = 2000;
	for (int i = 0; i < 3; i++) {
		int zz=0;
		cin >> zz;
		b = min(b, zz);
	}
	for (int i = 0; i < 2; i++) {
		int zz = 0;
		cin >> zz;
		g = min(g, zz);
	}
	cout << (b + g - 50);
}