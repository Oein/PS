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

int n, m;
vector<string> board;
bool visited[100][100];

int dfs(int x, int y, char c)
{
    int ret = 1;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (!visited[ny][nx] && board[ny][nx] == c)
            ret += dfs(nx, ny, c);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        board.push_back(s);
    }

    int w = 0, b = 0;

    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            if (!visited[y][x])
            {
                int cnt = dfs(x, y, board[y][x]);
                if (board[y][x] == 'W')
                    w += cnt * cnt;
                else
                    b += cnt * cnt;
            }

    cout << w << " " << b;
}
