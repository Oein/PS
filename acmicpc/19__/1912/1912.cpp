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
    vector<int> v(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    dp[0] = v[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + v[i], v[i]);
    }

    int max = dp[0];

    for (int i = 1; i < n; i++)
    {
        if (dp[i] > max)
        {
            max = dp[i];
        }
    }

    cout << max;
}
