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
#include <queue>
#include <numeric>

using namespace std;
using ll = long long;

int dp[50] = {0,1};

int main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n;i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}
