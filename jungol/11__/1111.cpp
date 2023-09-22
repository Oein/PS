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

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, hx, hy;
int board[105][105];
int visited[105][105];

struct QData
{
    int x;
    int y;
    int p;
};

struct QData_comp
{
    bool operator()(const QData &a, const QData &b) const
    {
        return a.p > b.p;
    }
};

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> hy >> hx;

    priority_queue<QData, vector<QData>, QData_comp> pq;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            visited[i][j] = 1234567890;
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
            {

                visited[i][j] = board[i][j] * board[i][j];
                pq.push({j, i, board[i][j] * board[i][j]});
            }
        }
    }

    while (!pq.empty())
    {
        QData qf = pq.top();
        pq.pop();

        if (qf.x == hx - 1 && qf.y == hy - 1)
        {
            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j < n; j++)
            //     {
            //         cout << visited[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            cout << qf.p;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = qf.x + dx[i];
            int ny = qf.y + dy[i];

            if (nx < 0)
                continue;
            if (ny < 0)
                continue;
            if (nx >= n)
                continue;
            if (ny >= n)
                continue;
            int dif = abs(board[ny][nx] - board[qf.y][qf.x]);
            int np = 0;
            if (board[ny][nx] > board[qf.y][qf.x])
                np = dif * dif;
            else if (board[ny][nx] < board[qf.y][qf.x])
                np = dif;
            if (visited[ny][nx] <= qf.p + np)
                continue;
            visited[ny][nx] = np + qf.p;
            pq.push({nx, ny, qf.p + np});
            // cout << "Calc " << nx << " , " << ny << " with power " << qf.p + np << "\n";
        }
    }
}