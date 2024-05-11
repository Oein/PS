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

int bottleSize, bottleCnt;
int bottle[16];
vector<int> priceByLiter;

int dp[1 << 16];

int dfs(int enabler)
{
    if (dp[enabler] != -1)
        return dp[enabler];

    int cnt = 0, sum = 0;
    // 하나로 몰방한 가격
    for (int i = 0; i < bottleCnt; i++)
    {
        if (enabler & (1 << i))
        {
            cnt++;
            sum += bottle[i];
        }
    }

    dp[enabler] = sum / bottleSize * priceByLiter[bottleSize];
    const int left = sum % bottleSize;
    if (left == 0) // 딱 맞아 떨어지면, 나머지를 0으로 채움
        dp[enabler] += priceByLiter[0] * (cnt - sum / bottleSize);
    else // 남은거 + 나머지를 0으로 채움
        dp[enabler] += priceByLiter[left] + (cnt - sum / bottleSize - 1) * priceByLiter[0];

    // 나눠서 생각한 경우
    for (int i = (enabler - 1) & enabler; i > 0; i = (i - 1) & enabler)
        dp[enabler] = max(dp[enabler], dfs(i) + dfs(enabler ^ i));

    return dp[enabler];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> bottleSize >> bottleCnt;
    for (int i = 0; i < bottleCnt; i++)
    {
        cin >> bottle[i];
    }
    for (int i = 0; i <= bottleSize; i++)
    {
        int x;
        cin >> x;
        priceByLiter.push_back(x);
    }

    cout << dfs((1 << bottleCnt) - 1);
}
