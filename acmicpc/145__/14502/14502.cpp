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

int h;
int w;

int board[10][10];

int ans = 0;

vector<Pos> virus;

void calcArea(vector<Pos> walls)
{
    int nboard[10][10];

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            nboard[i][j] = board[i][j];

    bool visited[10][10] = {
        0,
    };

    for (auto x : walls)
        nboard[x.y][x.x] = 1;

    for (auto vir : virus)
    {
        // spread virus

        queue<Pos> q;
        q.push(vir);
        visited[vir.y][vir.x] = 1;

        while (!q.empty())
        {
            auto qf = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + qf.x;
                int ny = dy[i] + qf.y;

                if (nx < 0)
                    continue;
                if (ny < 0)
                    continue;
                if (nx >= w)
                    continue;
                if (ny >= h)
                    continue;
                if (nboard[ny][nx])
                    continue;

                nboard[ny][nx] = 2;
                q.push({nx, ny});
            }
        }
    }

    int nno = 0;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (nboard[i][j] == 0)
                nno++;
    ans = max(nno, ans);
}

void pointDfs(vector<Pos> created)
{
    if (created.size() == 3)
        return calcArea(created);

    // create points
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            // check already defined

            bool cr = false;
            for (auto x : created)
            {
                if (x.x == j && x.y == i)
                {
                    cr = true;
                    break;
                }
            }

            if (board[i][j] > 0)
                continue;

            if (cr)
                continue;

            created.push_back({j, i});
            pointDfs(created);
            created.pop_back();
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.push_back({j, i});
        }

    pointDfs({});

    cout << ans;
}