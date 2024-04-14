#include <iostream>
#include <string>

using namespace std;

bool is_O(char a) {
	return a == 'O';
}

int main() {
	int cnt = 0;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		int combo = 0;
		int score = 0;

		string ox = "";
		cin >> ox;
		for (int j = 0; j < ox.size(); j++) {
			if (is_O(ox[j]) == true) {
				score += 1 + combo;
				combo++;
			}
			else {
				combo = 0;
			}
		}
		cout << score << '\n';
	}
}