#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<pair<int, int>> stoneCount;
vector<int> dp[100001]; // dp [의석 수] = vector<국회>

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n = 0;
	int mins = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		pair<int, int> p;
		cin >> p.first;
		p.second = i;
		stoneCount.push_back(p);
		mins += p.first;
	}

	mins /= 2;

	sort(stoneCount.begin(), stoneCount.end(), greater<>());

	int ans = 0; // 최대 의석수

	dp[0].push_back(-1);

	for (auto stone : stoneCount) {
		for (int i = mins; i >= 0; i--) { // mins 그 이상은 항상 그룹이 안됨
			int next = stone.first + i;
			if (!dp[i].empty() && dp[next].empty()) {
				ans = max(ans, next);
				dp[next] = dp[i];
				dp[next].push_back(stone.second);
			}
		}
	}

	cout << dp[ans].size() - 1 << "\n";
	for (auto x : dp[ans]) if (x > 0) cout << x << " ";
}