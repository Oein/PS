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

int m = 0;
int r = 0;
int rs[110];
int rt[110];
int memo[110];
int path[110];

int sol(int now)
{

    if (now == r)
    {
        memo[now] = 0;
        return 0;
    }

    if (memo[now] != -1)
        return memo[now];

    int n = now + 1;
    int low = sol(n);
    path[now] = n;
    n++;
    while (n <= r && rs[n] - rs[now] <= m)
    {
        int tmp = sol(n);
        if (low > tmp)
        {
            low = tmp;
            path[now] = n;
        }
        n++;
    }

    memo[now] = low + rt[now];
    return low + rt[now];
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    memset(memo, -1, sizeof(memo));

    cin >> m >> r;
    r++;

    for (int i = 1; i <= r; i++)
    {
        cin >> rs[i];
        rs[i] += rs[i - 1];
    }

    for (int i = 1; i < r; i++)
        cin >> rt[i];

    int sld = sol(0);

    cout << sld << "\n";

    if (sld == 0)
        return 0;

    int cnt = 0;
    for (int i = 0; path[i] != r; i = path[i], cnt++)
        ;

    cout << cnt << "\n";

    for (int i = 0; path[i] != r; i = path[i])
        cout << path[i] << " ";
}