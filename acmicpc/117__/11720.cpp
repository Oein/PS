#include <iostream>
#include <string>

using namespace std;


int main() {
	int cnt = 0;
	int v = 0;
	cin >> cnt;

	string d = "";
	cin >> d;

	for (int i = 0; i < cnt; i++) {
		v += d[i] - '0';
	}

	cout << v;
}