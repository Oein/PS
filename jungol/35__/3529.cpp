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
typedef vector<int> vi;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 2진수로 visited
int visited = 0;

int height, width;
string board[22];

int calc(int x, int y)
{
    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && nx <= width && ny > 0 && ny <= height && !(visited & (1 << (board[ny][nx] - 'a'))))
        {
            int lv = visited;
            visited |= (1 << (board[ny][nx] - 'a'));
            ret = max(ret, calc(nx, ny) + 1);
            visited = lv;
        }
    }

    return ret;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> height >> width;
    for (int i = 1; i <= height; i++)
    {
        cin >> board[i];
        board[i] = " " + board[i];
    }

    visited |= (1 << (board[1][1] - 'a'));
    int ans = calc(1, 1) + 1;

    cout << ans;
}