#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <numbers>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
int board[60][60];

int spreadPlus(int y, int x)
{
    int ans = 0;
    for (int i = max(y - m, 1); i <= min(y + m, n); i++)
    {
        ans += board[i][x];
    }
    for (int i = max(x - m, 1); i <= min(x + m, n); i++)
    {
        ans += board[y][i];
    }
    ans -= board[y][x];
    return ans;
}

int spreadX(int y, int x)
{
    int ans = 0;
    for (int i = 0; i <= m * 2; i++)
    {
        int ny = y + (i - m);
        int nx = x + (i - m);
        if (ny <= 0 || nx <= 0 || ny > n || nx > n)
            continue;
        ans += board[ny][nx];
    }

    for (int i = 0; i <= m * 2; i++)
    {
        int ny = y + (i - m);
        int nx = x + (m - i);
        if (ny <= 0 || nx <= 0 || ny > n || nx > n)
            continue;
        ans += board[ny][nx];
    }

    ans -= board[y][x];

    return ans;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans = max(ans, spreadPlus(i, j));
            ans = max(ans, spreadX(i, j));
        }
    }
    cout << ans;
}