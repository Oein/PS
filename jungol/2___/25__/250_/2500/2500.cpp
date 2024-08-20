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

int n, k;
int light_color[205];

// dp[p1][p2] = p1 ~ p2 까지 몇번 바꿔야 하는지.
int dp[205][205];

int dpFunction(int s, int e)
{
    if (s == e)
        return 0;
    if (dp[s][e])
        return dp[s][e];

    int ans = 1234567890;

    for (int spliter = s; spliter < e; spliter++)
    {
        ans = min(ans, dpFunction(s, spliter) + dpFunction(spliter + 1, e) + (light_color[s] != light_color[e]));
    }

    return dp[s][e] = ans;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> light_color[i];

    cout << dpFunction(1, n);
}