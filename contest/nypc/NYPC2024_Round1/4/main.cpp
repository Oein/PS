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

int n;
vector<int> arr;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << n;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        if (i == n - 1)
            dp.push_back(1);
        else
            dp.push_back(2);
    }

    // 세번째 item 처리
    if (arr[n - 1] > arr[n - 3])
    {
        dp[n - 3] = 3;
    }
    else
    {
        dp[n - 3] = 2;
    }

    if (n == 3)
    {
        cout << dp[0];
        return 0;
    }

    // 4번째 부터는 for

    int ans = dp[n - 3];

    for (int i = n - 4; i >= 0; i--)
    {
        if (arr[i] < arr[i + 2] && arr[i + 1] > arr[i + 3])
        {
            dp[i] = dp[i + 2] + 2;
            ans = max(ans, dp[i]);
            continue;
        }

        // 다음 참조는 불가
        if (arr[i] < arr[i + 2])
        {
            // 현재가 다음보다 작은거는 가능함
            dp[i] = 3;
            ans = max(ans, dp[i]);
            continue;
        }

        dp[i] = 2;
    }

    // print dp
    // for (auto i : dp)
    // {
    //     printf("%3d  ", i);
    // }
    // cout << endl;

    cout << ans;
}
