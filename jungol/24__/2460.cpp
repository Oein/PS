#include <iostream>
using namespace std;

int score[3][3];

int total(int player) {
	return (score[player][0]) * 1 + (score[player][1]) * 2 + (score[player][2]) * 3;
}

int main() {
	int n = 0 , winner = 0 ;
	bool error = false;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int input = 0;
			cin >> input;
			score[j][input - 1]++;
		}
	}
	for (int i = 1; i < 3; i++) {
		int winnerScore = total(winner);
		int nextScore = total(i);
		if (winnerScore < nextScore) {
			winner = i;
			error = false;
		}
		else if (winnerScore == nextScore) {
			for (int j = 2; j > -1; j--) {
				if (score[winner][j] < score[i][j]) {
					winner = i;
					error = false;
					break;
				}
				else if (score[winner][j] == score[i][j]) {
					if (j == 0) error = true;
				}
				else {
					break;
				}
			}
		}
	}

	if (error) cout << "0 " << total(winner);
	else cout << winner + 1 << " " << total(winner);
}
