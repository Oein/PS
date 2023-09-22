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

int p;
int likeBeer[1005];

int dp[1005][1005];
bool used[1005];

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> p;
    for (int i = 1; i <= p; i++)
    {
        cin >> likeBeer[i];
    }

    for (int j = 2; j <= p; j++)
    {
        for (int i = j - 1; i >= 1; i--)
        {
            // 홀수는 계산 X
            if ((j - i) % 2 == 0)
                continue;

            if (likeBeer[i] == likeBeer[j])
                dp[i][j] = dp[i + 1][j - 1] + 1;
            else
                dp[i][j] = dp[i + 1][j - 1];

            int max_ = 0;

            for (int k = 2; k <= (j - i); k += 2)
            {
                int tmp = dp[i + ((j - i) + 1 - k)][j] + dp[i][j - k];

                if (max_ < tmp)
                {
                    max_ = tmp;
                }
            }

            dp[i][j] = max(dp[i][j], max_);
        }
    }

    cout << dp[1][p];
}