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

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1, 0};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1, 0};

int n; // size of board
bool board[30][30];
// 어ㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓㅓ 왔다 갔다 하는거 어케하누;;
bool visited[30][30][30][30];

struct Pos
{
    int x;
    int y;
};

struct QData
{
    Pos c1;
    Pos c2;
};

Pos c1, c2, e1, e2;

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c1.y >> c1.x >> e1.y >> e1.x >> c2.y >> c2.x >> e2.y >> e2.x;

    c1.y--;
    c1.x--;
    c2.y--;
    c2.x--;
    e1.y--;
    e2.y--;
    e1.x--;
    e2.x--;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    unsigned int t = 0;
    queue<QData> q;
    q.push({c1, c2});

    while (!q.empty())
    {
        unsigned long qs = q.size();

        while (qs--)
        {
            QData qf = q.front();
            q.pop();

            bool c1c = qf.c1.x == e1.x && qf.c1.y == e1.y;
            bool c2c = qf.c2.x == e2.x && qf.c2.y == e2.y;

            if (c1c && c2c)
            {
                cout << t;
                return 0;
            }

            for (int c1d = 0; c1d < 9; c1d++)
            {
                Pos nc1 = qf.c1;
                nc1.x += dx[c1d];
                nc1.y += dy[c1d];

                if (nc1.x < 0 || nc1.y < 0 || nc1.x >= n || nc1.y >= n)
                    continue;

                if (board[nc1.y][nc1.x])
                    continue;

                for (int c2d = 0; c2d < 9; c2d++)
                {
                    Pos nc2 = qf.c2;
                    nc2.x += dx[c2d];
                    nc2.y += dy[c2d];

                    if (nc2.x < 0 || nc2.y < 0 || nc2.x >= n || nc2.y >= n)
                        continue;

                    if (board[nc2.y][nc2.x])
                        continue;

                    if (visited[nc1.y][nc1.x][nc2.y][nc2.x])
                        continue;

                    if (abs(nc1.y - nc2.y) <= 1 && abs(nc1.x - nc2.x) <= 1)
                        continue;

                    visited[nc1.y][nc1.x][nc2.y][nc2.x] = 1;
                    q.push({nc1,
                            nc2});
                }
            }
        }

        t++;
    }
}