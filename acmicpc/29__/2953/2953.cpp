#include <iostream>
using namespace std;

int main()
{
	int arr[5][4];
	int maxScore = 0;
	int allScore;
	int winner;
	for (int i = 0; i < 5; i++) {
		allScore = 0;
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
			allScore += arr[i][j];
		}
		if (allScore > maxScore) {
			maxScore = allScore;
			winner = i + 1;
		}
	}

	cout << winner << " " << maxScore << '\n';

	return 0;
}