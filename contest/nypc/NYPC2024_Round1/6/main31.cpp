#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

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

bool board[205][205] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    if (n > 200)
    {
        printf("NO\n");
        return 0;
    }

    for (int i = 0; i < k; i++)
    {
        int x, y, p;
        cin >> x >> y >> p;
        for (int j = max(1, x - p); j <= min(n, x + p); j++)
        {
            board[y][j] = 1;
        }
        for (int j = max(1, y - p); j <= min(n, y + p); j++)
        {
            board[j][x] = 1;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i][j] == 0)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
