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

int n, m ,k;

string reqString = "";
vector<string> board;

bool isInside(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

int ans = 0;
int cache[101][101][81] = {0,};

int dfs(int x, int y, int step) {
    // printf("(%d, %d) %d\n", x, y, step);
    if(cache[x][y][step] != -1)
        return cache[x][y][step];
    if(step == reqString.size() - 1)
        return 1;
    int res = 0;
    for(int dir = 0;dir < 4;dir++) {
        for(int m = 1;m <= k;m++) {
            int nx = x + dx[dir] * m;
            int ny = y + dy[dir] * m;

            if(!isInside(nx, ny)) break;
            if(board[ny][nx] != reqString[step + 1]) continue;
            res += dfs(nx, ny, step + 1);
        }
    }
    cache[x][y][step] = res;
    return res;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0;i < n;i++) {
        string x;
        cin >> x;
        board.push_back(x);
    }

    cin >> reqString;

    for(int y = 0; y < n; y++) {
        for(int x = 0;x < m;x++) {
            if(board[y][x] != reqString[0]) continue;
            ans += dfs(x, y, 0);
        }
    }

    cout << ans;
}
