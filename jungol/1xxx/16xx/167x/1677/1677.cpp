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

#define dout(X) \
    if (X)      \
    cout

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 1, -1};
int dy[] = {1, 0, 0};

const int memoUndefined = 100 * 1000 * 1000 * -1 - 5;

int n;
int a[1005][1005];
int memo[1005][1005][3];
bool visited[1005][1005];

struct PAIR
{
    int a;
    int b;
};

enum FROM
{
    UP = 0,
    LEFT = 1,
    RIGHT = 2
};

FROM cast_as_(int n)
{
    if (n == 0)
        return FROM::UP;
    if (n == 1)
        return FROM::LEFT;
    if (n == 2)
        return FROM::RIGHT;
    return FROM::UP;
}

// n²logn

/**
 * @brief 어떤 위치에서 이동을 시작했을때 최고 점수가 얼마인지 구한다.
 *
 * @param x Location.x
 * @param y Location.y
 * @param from Location을 기준으로 어디서 호출했는지
 */
int dfs(int x, int y, FROM from)
{
    // end
    if (x == n - 1 && y == n - 1)
        return a[y][x];

    // memoization
    if (memo[y][x][from] != memoUndefined)
        return memo[y][x][from];

    // return value
    int maxScore = memoUndefined;

    // calc
    for (itn dir = 0; dir < 3; dir++)
    {
        FROM casted = cast_as_(dir);

        int nx = dx[dir] + x;
        int ny = dy[dir] + y;

        if (nx < 0)
            continue;
        if (ny < 0)
            continue;
        if (nx >= n)
            continue;
        if (ny >= n)
            continue;
        if (visited[ny][nx])
            continue;

        visited[ny][nx] = 1;
        maxScore = max(maxScore, dfs(nx, ny, casted));
        visited[ny][nx] = 0;
    }

    // return
    maxScore += a[y][x];
    memo[y][x][from] = maxScore;
    return maxScore;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            memo[i][j][FROM::LEFT] = memoUndefined;
            memo[i][j][FROM::RIGHT] = memoUndefined;
            memo[i][j][FROM::UP] = memoUndefined;
        }
    }

    visited[0][0] = 1;
    cout << dfs(0, 0, FROM::LEFT);
}