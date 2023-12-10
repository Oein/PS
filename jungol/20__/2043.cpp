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

int table[20][20] = {
    0,
};

int dp[1 << 16] = {
    0,
};
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> table[i][j];

    for (int i = 0; i < (1 << 16); i++)
        dp[i] = 1;

    for (int bit = 1; bit < (1 << n); bit++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
                cnt++;
        }

        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                temp = (temp + (dp[bit ^ (1 << i)] * table[cnt - 1][i])) % 10000;
            }
        }
        dp[bit] = temp % 10000;
    }

    cout << dp[(1 << n) - 1];
}
