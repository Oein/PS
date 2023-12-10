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

int buildCost[25][25];
int n;

struct DP
{
    int cost;
    int create;
    int from;
};
DP dp[1 << 20];

void printFrom(int bit)
{
    if (bit == 0)
        return;
    printFrom(dp[bit].from);
    cout << dp[bit].create << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> buildCost[i][j];

    for (int bit = 1; bit < (1 << n); bit++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
                cnt++;
        }

        dp[bit].cost = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                int tmp = dp[bit ^ (1 << i)].cost + buildCost[cnt - 1][i];
                if (dp[bit].cost > tmp)
                {
                    dp[bit].cost = tmp;
                    dp[bit].create = i + 1;
                    dp[bit].from = bit ^ (1 << i);
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].cost << '\n';
    printFrom((1 << n) - 1);
}
