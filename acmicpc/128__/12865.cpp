#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include <limits>
#include <string>
#include <cmath>
#include <stack>
#include <climits>
using namespace std;
using ll = long long;

struct Gem {
    int weight;
    int price;
};

vector<Gem> gems;

int dp[105][100005] = {0,};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, bag;
    cin >> n >> bag;
    gems.push_back({0,0});
    for(int i = 0;i < n;i++) {
        int p, w;
        cin >> w >> p;
        gems.push_back({w,p});
    }
    
    // 보석
    for(int i = 1; i <= n; i++) {
        // 무게
        for(int j = 1; j <= bag; j++) {
            dp[i][j] = dp[i - 1][j];
            // 이전 보석 최댓값으로
            if(gems[i].weight <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - gems[i].weight] + gems[i].price);
        }
    }
    cout << dp[n][bag];
}
