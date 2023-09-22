#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <stack>
#include <cstring>

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const int Mod = 1000000003;

int dp[1005][1005];
int n, k;

int dpfunction(int n, int k)
{
    if (k == 1)
        return n;
    if (n <= 0)
        return 0;
    if (n < k * 2)
        return 0;
    if (dp[n][k] != -1)
        return dp[n][k];
    return dp[n][k] = (dpfunction(n - 2, k - 1) + dpfunction(n - 1, k)) % Mod;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << dpfunction(n, k);
}