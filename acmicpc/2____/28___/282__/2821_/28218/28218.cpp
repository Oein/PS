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

int n, m, k;
string board[303];
int dp[303][303];

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && board[x][y] == '.';
}

int solve(int x, int y) {
    if(dp[y][x] != -1) return dp[y][x];
    if(valid(x + 1, y) && !solve(x + 1, y)) return dp[y][x] = 1;
    if(valid(x, y + 1) && !solve(x, y + 1)) return dp[y][x] = 1;
    for(int i = 1;i <= k;i++) {
        if(valid(x + i, y + i) && !solve(x + i, y + i)) return dp[y][x] = 1;
    }
    return dp[y][x] = 0;
    
}

void solve() {
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    if(solve(x, y)) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) {
        cin >> board[i];
    }
    dp[n - 1][m - 1] = 0;

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}
