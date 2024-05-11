#include <iostream>
#include <string>

using namespace std;

int main() {
	int v[3] = { 0, };
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}
	string x = to_string(v[0] * v[1] * v[2]);
	int datas[10] = { 0, };

	for (int i = 0; i < x.size(); i++) {
		int v = x[i] - '0';
		datas[v]++;
	}
	for (int i = 0; i < 10; i++) {
		cout << datas[i] << "\n";
	}
}