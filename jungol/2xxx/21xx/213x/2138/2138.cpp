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

#define interface struct
#define zx3f 1061109567
#define itn int

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
int dp[10005][13];

int dpFunciton(int n, int state)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return state == 0;
    int res = dp[n][state];
    if (res != -1)
        return res;

    res = 0;

    if (state == 0)
    {
        res = (res + dpFunciton(n - 1, 0)) % m;
        res = (res + dpFunciton(n - 1, 3)) % m;
        res = (res + dpFunciton(n - 1, 9)) % m;
        res = (res + dpFunciton(n - 1, 12)) % m;
        res = (res + dpFunciton(n - 2, 0)) % m;
    }

    if (state == 3)
    {
        res = (res + dpFunciton(n - 1, 0)) % m;
        res = (res + dpFunciton(n - 1, 12)) % m;
    }

    if (state == 6)
    {
        res = (res + dpFunciton(n - 1, 9)) % m;
    }

    if (state == 9)
    {
        res = (res + dpFunciton(n - 1, 0)) % m;
        res = (res + dpFunciton(n - 1, 6)) % m;
    }

    if (state == 12)
    {
        res = (res + dpFunciton(n - 1, 0)) % m;
        res = (res + dpFunciton(n - 1, 3)) % m;
    }

    return dp[n][state] = res % m;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;

    cout << dpFunciton(n, 0);
}