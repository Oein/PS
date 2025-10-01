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

int board[1005][1005];
int goalX, goalY;
int need[1005][1005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            need[i][j] = -1;
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                goalX = i;
                goalY = j;
                board[i][j] = 1;
            }
            if (board[i][j] == 0)
                need[i][j] = 0;
        }

    queue<Pos> q;
    q.push({goalX, goalY});

    int t = 1;

    while (!q.empty())
    {
        unsigned long long qs = q.size();
        while (qs--)
        {
            Pos qf = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = qf.x + dx[i];
                int ny = qf.y + dy[i];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;

                // 원래 못가거나, 이미 방문했으면 패스
                if (board[nx][ny] == 0 || need[nx][ny] > 0)
                    continue;

                need[nx][ny] = t;

                q.push({nx, ny});
            }
        }

        t++;
    }

    need[goalX][goalY] = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cout << need[i][j] << " ";
        cout << "\n";
    }
}
