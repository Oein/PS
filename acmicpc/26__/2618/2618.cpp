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

int n, w;
int dp[1005][1005] = {
    0,
};
vector<Pos> events;

int calcDist(int fx, int fy, int tx, int ty)
{
    return abs(fx - tx) + abs(fy - ty);
}

int solve(int a, int b)
{
    if (a == w || b == w)
        return 0;

    if (dp[a][b] != -1)
        return dp[a][b];

    int next = max(a, b) + 1;

    int case1 = 0;
    int case2 = 0;

    auto event = events[next];

    if (a == 0)
        case1 = calcDist(1, 1, event.x, event.y);
    else
        case1 = calcDist(events[a].x, events[a].y, event.x, event.y);

    if (b == 0)
        case2 = calcDist(n, n, event.x, event.y);
    else
        case2 = calcDist(events[b].x, events[b].y, event.x, event.y);

    int res1 = case1 + solve(next, b);
    int res2 = case2 + solve(a, next);

    return dp[a][b] = min(res1, res2);
}
void move(int a, int b)
{
    if (a == w || b == w)
        return;
    int next = max(a, b) + 1;
    int case1 = 0, case2 = 0;

    auto event = events[next];
    if (a == 0)
        case1 = calcDist(1, 1, event.x, event.y);
    else
        case1 = calcDist(events[a].x, events[a].y, event.x, event.y);

    if (b == 0)
        case2 = calcDist(n, n, event.x, event.y);
    else
        case2 = calcDist(events[b].x, events[b].y, event.x, event.y);

    if (dp[next][b] + case1 < dp[a][next] + case2)
    {
        cout << 1 << "\n";
        move(next, b);
    }
    else
    {
        cout << 2 << "\n";
        move(a, next);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n >> w;
    events.resize(w + 1);
    for (int i = 1; i <= w; i++)
    {
        cin >> events[i].x >> events[i].y;
    }

    // init
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0) << "\n";
    move(0, 0);
}
