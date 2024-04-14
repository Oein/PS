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

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n; // wanna go
int m; // cannot go

bool canNotGo[105];

int price[105][105];

int dp(int day, int free)
{
    if (day > n)
        return 0;
    if (price[day][free] != 1234567890)
        return price[day][free];
    if (canNotGo[day])
        return price[day][free] = dp(day + 1, free);

    int ans = price[day][free];

    ans = min(ans, dp(day + 1, free) + 10000);
    ans = min(ans, dp(day + 3, free + 1) + 25000);
    ans = min(ans, dp(day + 5, free + 2) + 37000);
    if (free >= 3)
        ans = min(ans, dp(day + 1, free - 3));

    return price[day][free] = ans;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        canNotGo[x] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            price[i][j] = 1234567890;
        }
    }

    cout << dp(1, 0);
}