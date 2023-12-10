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

struct isLand
{
    int x;
    int spring;
    bool withOrange;
};

vector<isLand> islands;
int n;

int dp[505][505] = {
    0,
};

int func(int g1, int g2)
{
    int &ret = dp[g1][g2];
    if (ret != -1)
        return ret;

    if (g1 == n - 1)
    {
        if (islands[n - 1].x - islands[g2].x <= islands[n - 1].spring)
            return ret = 1;
        else
            return ret = 0;
    }
    if (g2 == n - 1)
        return ret = 0;

    int next = max(g1, g2) + 1;
    ret = 0;
    for (int i = next; i < n; i++)
    {
        if (islands[i].x - islands[g1].x <= islands[g1].spring)
        {
            ret = ret + func(i, g2);
            ret %= 1000;
        }
        if (islands[i].x - islands[g2].x <= islands[i].spring && islands[i].withOrange == 1)
        {
            ret = ret + func(g1, i);
            ret %= 1000;
        }
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    islands.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> islands[i].x >> islands[i].spring >> islands[i].withOrange;
    }

    cout << func(0, 0);
}
