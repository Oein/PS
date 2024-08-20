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

vector<string> board;

bool visited[105][105];
bool visited2[105][105];

int n;

void calc(int y, int x)
{
    queue<Pos> q;
    q.push({x, y});
    visited[y][x] = true;

    while (!q.empty())
    {
        Pos qf = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + qf.x;
            int ny = dy[i] + qf.y;

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
            if (board[ny][nx] != board[y][x])
                continue;

            visited[ny][nx] = 1;

            q.push({nx, ny});
        }
    }
}

void calc2(int y, int x)
{
    queue<Pos> q;
    q.push({x, y});
    visited2[y][x] = true;

    while (!q.empty())
    {
        Pos qf = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + qf.x;
            int ny = dy[i] + qf.y;

            if (nx < 0)
                continue;
            if (ny < 0)
                continue;
            if (nx >= n)
                continue;
            if (ny >= n)
                continue;

            if (visited2[ny][nx])
                continue;
            if (board[y][x] == 'B' && board[ny][nx] != 'B')
                continue;
            if ((board[y][x] == 'G' || board[y][x] == 'R') && board[ny][nx] == 'B')
                continue;

            visited2[ny][nx] = 1;

            q.push({nx, ny});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        board.push_back(x);
    }

    int a = 0, b = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                calc(i, j);
                a++;
            }
            if (!visited2[i][j])
            {
                calc2(i, j);
                b++;
            }
        }

    cout << a << " " << b;
}