#include <iostream>
using namespace std;

int main()
{
	int note[8];
	int mode = 0;
	int cheek = 0;
	for (int i = 1; i < 9; i++) {
		note[i - 1] = 0;
		cin >> note[i-1];
		if (i == 1) {
			if (note[i-1] == 1) {
				mode = 1;
				cheek++;
			}
			else if (note[i-1] == 8) {
				mode = 3;
				cheek++;
			}
			else if (i == 1) mode == 2;
		}
		else {
			if (mode == 1) {
				if (note[i-1] != i) mode = 2;
			}
			else if (mode == 3) {
				if ((i == 2 && note[i - 1] != 7) || (i == 3 && note[i - 1] != 6) || (i == 4 && note[i - 1] != 5) || (i == 5 && note[i - 1] != 4) || (i == 6 && note[i - 1] != 3) || (i == 7 && note[i - 1] != 2) || (i == 8 && note[i - 1] != 1)) mode = 2;
			}
		}
	}
	if (mode == 1)cout << "ascending";
	else if (mode == 3)cout << "descending";
	else cout << "mixed";
	return 0;
}