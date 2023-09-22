#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	bool check[31];
	for (int i = 0; i < 31; i++) {
		check[i] = false;
	}
	check[0] = true;
	for (int i = 0; i < 28; i++) {
		int num = 0;
		cin >> num;
		check[num] = true;
	}
	for (int i = 0; i < 31; i++) {
		if (check[i] == false) {
			cout << i << '\n';
		}
	}



	/*int pipoolnum[31];
	bool ch[31];
	int n = 0, m = 0;
	for (int oi = 0; oi < 28; oi++) {
		pipoolnum[oi] = 0;
		ch[oi] = 0;
	}
	ch[28] = 0;
	ch[29] = 0;
	for (int oi = 0; oi < 28; oi++) {
		cin >> pipoolnum[oi];
	}
	for (int i = 0; i < 30; i++) {
		ch[i] = true;
	}
	for (int i = 0; i < 30; i++) {
		if (ch[i] == 0) {
			if (n == 0) {
				n = i;
			}
			else
			{
				m = i;
			}
		}
	}
	cout << min(n, m) << '\n' << max(n, m);*/
}