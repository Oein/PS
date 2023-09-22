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

unsigned long long dp[100] = {0,1};

int main() {
    unsigned long long n;
    cin >> n;
    for(unsigned long long i = 2; i <= n;i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}
