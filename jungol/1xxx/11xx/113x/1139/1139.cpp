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

int n;
vector<Pos> v;

double dp[105][105] = {
    0,
};

double calcDist(int f, int t)
{
    Pos a = v[f];
    Pos b = v[t];
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Pos x;
        cin >> x.x >> x.y;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), [](const Pos a, const Pos b)
         { return a.x < b.x; });

    queue<pair<int, int>> q;
    q.push({0, 0});

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            dp[i][j] = INT_MAX;
    }
    dp[0][0] = 0;
    dp[0][1] = calcDist(0, 1);
    dp[1][0] = calcDist(0, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int next = max(i, j) + 1;
            dp[next][j] = min(dp[i][j] + calcDist(i, next), dp[next][j]);
            dp[i][next] = min(dp[i][j] + calcDist(j, next), dp[i][next]);

            // cout << i << " & " << j << " > " << next << " / " << dp[next][j] << ", " << dp[i][next] << "\n";
        }
    }

    // A end check
    double ans = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        double a = dp[n - 1][i] + calcDist(i, n - 1);
        double b = dp[i][n - 1] + calcDist(i, n - 1);
        // cout << i << " / " << a << " " << b << "\n";
        ans = min(ans, min(a, b));
    }

    printf("%.2f", ans);
}