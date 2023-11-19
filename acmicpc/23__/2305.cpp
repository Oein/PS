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
#include <climits>

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Pos
{
    int x;
    int y;
};

int n, k;
int fibo[45] = {1, 1};
int fibosum[45] = {1, 1};
int dp[45] = {
    0,
    0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    for (int i = 2; i <= n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibosum[i] = fibosum[i - 1] + fibo[i];
    }

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + fibosum[i - 1];

    cout << dp[k] * fibo[n - k] + dp[n - k + 1] * fibo[k - 1] + fibo[k - 1] * fibo[n - k];
}