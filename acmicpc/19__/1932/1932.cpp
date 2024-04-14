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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v(n);
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int y = 0; y < n; y++)
        for (int x = 0; x <= y; x++)
        {
            int t;
            cin >> t;
            v[y].push_back(t);
            if (y == n - 1)
                dp[y][x] = t;
        }

    for (int y = n - 2; y >= 0; y--)
        for (int x = 0; x <= y; x++)
        {
            dp[y][x] = max(dp[y + 1][x], dp[y + 1][x + 1]) + v[y][x];
        }

    // for (int i = 0; i < n; i++)
    // {
    //     for (auto j : dp[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[0][0];
}
