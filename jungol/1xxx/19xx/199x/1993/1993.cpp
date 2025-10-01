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

int cost[4][4] = {
    {100, 70, 40, 0},
    {70, 50, 30, 0},
    {40, 30, 20, 0},
    {0, 0, 0, 0}};
int board[12][12];
int dp[12][12][1 << 12];

int n, now_bit, right_bit, down_bit, mod_bit;

int calc(int x, int y, int bit)
{
    if (y == n)
    {
        y = 0;
        x++;
    }
    if (x == n)
        return 0;

    int &ret = dp[x][y][bit];
    if (ret != -1)
        return ret;

    ret = 0;

    if (!(bit & now_bit))
    {
        int now_ = board[x][y], next_ = 0, dt;

        if (y + 1 < n && !(bit & right_bit))
        {
            next_ = board[x][y + 1];
            dt = calc(x, y + 2, (bit << 2) % mod_bit) + cost[now_][next_];
            ret = max(ret, dt);
        }
        if (x + 1 < n && !(bit & down_bit))
        {
            next_ = board[x + 1][y];
            dt = calc(x, y + 1, ((bit | down_bit) << 1) % mod_bit) + cost[now_][next_];
            ret = max(ret, dt);
        }
    }

    int dt = calc(x, y + 1, (bit << 1) % mod_bit); // skip this block
    ret = max(ret, dt);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    now_bit = (1 << n);
    right_bit = (1 << (n - 1));
    down_bit = 1;
    mod_bit = (1 << (n + 1));

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            board[i][j] = x == 'F' ? 3 : x - 'A';
        }

    // ??????_____
    // _______????
    // 의 상태를 저장

    cout << calc(0, 0, 0);
}
