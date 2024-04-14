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

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int m_height, m_width;
int m[505][505];
int dp[505][505];

int dfs(int y, int x)
{
    if (y == m_height - 1 && x == m_width - 1)
        return 1;
    if (dp[y][x] != -1)
        return dp[y][x];
    dp[y][x] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx < 0)
            continue;
        if (ny < 0)
            continue;
        if (nx >= m_width)
            continue;
        if (ny >= m_height)
            continue;
        if (m[y][x] <= m[ny][nx])
            continue;
        dp[y][x] += dfs(ny, nx);
    }

    return dp[y][x];
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> m_height >> m_width;

    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            cin >> m[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0);
}