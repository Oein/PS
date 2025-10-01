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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct Pos
{
    int x;
    int y;
};

int n, m;
int ansX, ansY;

// 좌표는 1부터 시작
int board[1005][1005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int x = 1, y = 1;
    int dir = 0;
    int goT = n;
    int nowFill = n * n;
    while (nowFill > 0 && goT > 0)
    {
        if (dir == 0)
            goT--;
        for (int i = 0; i < goT; i++)
        {
            // cout << x << ", " << y << " : F" << nowFill << " / D" << dir << " / GT" << goT << "\n";
            board[y][x] = nowFill;
            if (nowFill == m)
            {
                ansX = x;
                ansY = y;
            }
            nowFill--;

            x += dx[dir];
            y += dy[dir];
        }

        if (dir == 3)
        {
            x++;
            y++;
            goT--;
        }

        dir = (dir + 1) % 4;
    }

    board[n / 2 + 1][n / 2 + 1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    cout << ansY << " " << ansX;
}
