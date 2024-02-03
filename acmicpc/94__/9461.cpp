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

unsigned long long p(int x)
{
    if (x == 1 || x == 2 || x == 3)
        return 1;
    if (x == 4 || x == 5)
        return 2;
    unsigned long long dp[101] = {0, 1, 1, 1, 2, 2};
    for (int i = 6; i <= x; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << p(x) << "\n";
    }
}
