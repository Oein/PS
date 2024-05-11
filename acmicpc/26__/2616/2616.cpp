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

int n, m;
int presum[50005];
int people[50005];
int dp[5][50005];

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> people[i];
        presum[i] = presum[i - 1] + people[i];
    }
    cin >> m;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = i * m; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + presum[j] - presum[j - m]);
        }
    }
    cout << dp[3][n];
}