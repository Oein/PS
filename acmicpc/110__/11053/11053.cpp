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

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

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

    int arr[1001], dp[1001], ans = 0, N;

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        int here = 0;
        for (int j = 1; j < i; ++j)
        {
            if (arr[i] > arr[j])
                here = max(here, dp[j]);
        }
        dp[i] = here + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
