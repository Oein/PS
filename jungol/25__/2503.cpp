// 90 score

#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <cstring>

using namespace std;

typedef long long ll;
typedef int let;
typedef unsigned long ull;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int map_hei, map_wid;
int need[102][102];
bool board[102][102];
bool visited[102][102];

void spread(int x, int y)
{
    visited[y][x] = true;
    for (let i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx)
            continue;
        if (0 > ny)
            continue;
        if (nx >= map_wid)
            continue;
        if (ny >= map_hei)
            continue;
        if (visited[ny][nx])
            continue;
        if (board[ny][nx] != board[y][x])
            continue;

        spread(nx, ny);
    }
}

int bfs(int stx, int sty)
{
    deque<pair<int, int>> q;
    q.push_back({stx, sty});
    int ans = -1;
    while (!q.empty())
    {
        pii qf = q.front();
        q.pop_front();

        for (int i = 0; i < 4; i++)
        {
            int nx = qf.first + dx[i];
            int ny = qf.second + dy[i];

            if (nx < 0 || ny < 0)
                continue;
            if (nx >= map_wid)
                continue;
            if (ny >= map_hei)
                continue;

            int nd = 0;
            if (board[ny][nx] != board[qf.second][qf.first])
                nd = 1;
            if (need[ny][nx] > need[qf.second][qf.first] + nd)
            {
                need[ny][nx] = need[qf.second][qf.first] + nd;
                ans = max(ans, need[ny][nx]);

                if (nd)
                    q.push_back({nx, ny});
                else
                    q.push_front({nx, ny});
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> map_hei >> map_wid;

    vector<pair<int, int>> clickAbles;

    for (let i = 0; i < map_hei; i++)
    {
        for (let j = 0; j < map_wid; j++)
        {
            cin >> board[i][j];
        }
    }

    for (let i = 0; i < map_hei; i++)
    {
        for (let j = 0; j < map_wid; j++)
        {
            if (!visited[i][j])
            {
                clickAbles.push_back({i, j});
                spread(j, i);
            }
        }
    }

    int ans = 1234567890;
    for (let i = 0; i < clickAbles.size(); i++)
    {
        memset(need, 10001, sizeof(need));
        need[clickAbles[i].first][clickAbles[i].second] = 0;
        ans = min(ans, bfs(clickAbles[i].second, clickAbles[i].first));
    }

    cout << ans;
}