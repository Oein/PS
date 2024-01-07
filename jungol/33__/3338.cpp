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

map<pair<int, int>, int> dp;

int solve(ll x, ll y)
{
    if (x == 0 && y == 0)
        return 0;
    if (dp.find({x, y}) != dp.end())
        return dp[{x, y}];

    // cout << "C";

    int ret = 0;
    for (int i = 1; i <= 40; i++)
    {
        ll s = (1ll << i) - 1;
        ll e = (1ll << (i + 1)) - 2;

        s = max(s, x);
        e = min(e, y);

        ll s2 = s - (1ll << i) + 1;
        ll e2 = e - (1ll << i) + 1;

        // continue;
        if (s <= e)
            ret = max(ret, solve(s2, e2) + i);

        // cout << "s: " << s << "  e: " << e << "\n";
    }
    return dp[{x, y}] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
}
