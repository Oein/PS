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
vector<char> cards;
vector<pair<int, char>> path[505];

int dp[1005][505];

int dfs(int point, int moved)
{
    if (moved == n)
        return 0;

    int &ans = dp[moved][point];

    if (ans != -1)
        return ans;
    ans = 0;

    for (auto n : path[point])
    {
        ans = max(ans,
                  dfs(n.first, moved + 1) + (n.second == cards[moved] ? 10 : 0));
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof dp);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        cards.push_back(x);
    }

    cin >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        char color;
        cin >> x >> y >> color;
        path[x].push_back({y, color});
        path[y].push_back({x, color});
    }

    cout << dfs(1, 0);
}
