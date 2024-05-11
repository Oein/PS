#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int m, n, h;
int board[105][105][105];
bool visited[105][105][105];

struct XYZ_MC
{
    int x;
    int y;
    int h;
};

XYZ_MC dxyz[] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {-1, 0, 0},
    {0, -1, 0},
    {0, 0, -1}};

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> h;
    queue<XYZ_MC> q;
    int needToSpread = 0;

    for (int i = 0; i < h; i++) // h
    {
        for (int j = 0; j < n; j++) // y
        {
            for (int k = 0; k < m; k++) // x
            {
                // h y x
                cin >> board[i][j][k];
                // h y x
                if (board[i][j][k] == 1)
                {
                    // x y z
                    q.push({k, j, i});
                    // h y x
                    visited[i][j][k] = true;
                }
                // h y x
                else if (board[i][j][k] == 0)
                {
                    needToSpread++;
                }
            }
        }
    }

    int t = 0;

    while (!q.empty() && needToSpread > 0)
    {
        unsigned long qs = q.size();
        while (qs--)
        {
            XYZ_MC qf = q.front();
            q.pop();

            for (int i = 0; i < 6; i++)
            {
                XYZ_MC nxyz = qf;
                nxyz.x += dxyz[i].x;
                nxyz.y += dxyz[i].y;
                nxyz.h += dxyz[i].h;
                if (nxyz.x < 0 || nxyz.x >= m)
                    continue;
                if (nxyz.y < 0 || nxyz.y >= n)
                    continue;
                if (nxyz.h < 0 || nxyz.h >= h)
                    continue;
                if (visited[nxyz.h][nxyz.y][nxyz.x])
                    continue;
                if (board[nxyz.h][nxyz.y][nxyz.x] == -1)
                    continue;

                visited[nxyz.h][nxyz.y][nxyz.x] = true;
                if (board[nxyz.h][nxyz.y][nxyz.x] == 0)
                {
                    needToSpread--;
                }
                board[nxyz.h][nxyz.y][nxyz.x] = 1;
                q.push(nxyz);
            }
        }
        t++;
    }

    if (needToSpread)
    {
        cout << "-1";
        return 0;
    }

    cout << t;
}