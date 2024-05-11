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

#define interface struct
#define zx3f 1061109567

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int mn, cp;
int earn[25][305];
int dp[25][305];
int track_[25][305];
int ans[25];

void calc(int company, int money)
{
    if (company == 0)
        return;
    ans[company] = track_[company][money];
    calc(company - 1, money - ans[company]);
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> mn >> cp;
    for (int i = 1; i <= mn; i++)
    {
        int tm;
        cin >> tm;
        for (int j = 1; j <= cp; j++)
        {
            cin >> earn[j][tm];
        }
    }

    for (int i = 1; i <= cp; i++)
    {
        for (int cost = 1; cost <= mn; cost++)
        {
            if (i == 0)
            {
                dp[i][cost] = earn[i][cost];
                track_[i][cost] = cost;
            }
            for (int j = 0; j <= cost; j++)
            {
                int tans = dp[i - 1][cost - j] + earn[i][j];
                if (tans > dp[i][cost])
                {
                    dp[i][cost] = tans;
                    track_[i][cost] = j;
                }
            }
        }
    }

    cout << dp[cp][mn] << "\n";

    calc(cp, mn);

    for (int i = 1; i <= cp; i++)
    {
        cout << ans[i] << " ";
    }
}