#include <iostream>
#include <algorithm>

using namespace std;

int gae_dan_scores[301];
int dp[301];

int main() {
	int count_of_gae_dan = 0;
	cin >> count_of_gae_dan;
	for (int i = 1; i <= count_of_gae_dan; i++) {
		cin >> gae_dan_scores[i];
	}

	dp[1] = gae_dan_scores[1];
	dp[2] = gae_dan_scores[1] + gae_dan_scores[2];
	dp[3] = max(gae_dan_scores[1] + gae_dan_scores[3], gae_dan_scores[2] + gae_dan_scores[3]);

	for (int i = 4; i <= count_of_gae_dan; i++) {
		// 2번째 전꺼의 최대값 + 자신
		// 3번째 전꺼의 최댓값 + 전 계단 + 자신
		// 1 3
		// 0 2 3
		dp[i] = max(dp[i-2] + gae_dan_scores[i] , dp[i - 3] + gae_dan_scores[i - 1] + gae_dan_scores[i]);
	}

	cout << dp[count_of_gae_dan];
}