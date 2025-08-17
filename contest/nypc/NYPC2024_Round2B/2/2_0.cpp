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
    ll x;
    ll y;
};

#define MOD 1000000007

using YPOS = ull;
using DIFF = ll;
using COUNT = ull;
using STEP_CNT = ull;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> stp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> stp[i];
    }

    map<YPOS, map<DIFF, STEP_CNT>> dp;

    for (int i = n - 2; i >= 0; i--)
    {
        // printf("i: %d\n", i);
        map<DIFF, COUNT> making_global_cache;
        set<DIFF> global_cache_used;
        for (int j = n - 1; j > i; j--)
        {
            // printf("  j: %d\n", j);
            const ll diff = stp[j] - stp[i];
            if (diff == 0)
                continue;
            if (global_cache_used.find(diff) != global_cache_used.end())
                continue;

            if (dp.find(stp[j]) != dp.end() && dp[stp[j]].find(diff) != dp[stp[j]].end())
            {
                // COUNT = 발판의 개수
                STEP_CNT x = dp[stp[j]][diff];
                global_cache_used.insert(diff);
                dp[stp[i]][diff] = x * 2;
                while (dp[stp[i]][diff] >= MOD)
                {
                    dp[stp[i]][diff] -= MOD;
                }

                continue;
            }

            // global cache가 존재 하지 않음
            making_global_cache[diff]++;
        }

        for (auto &p : making_global_cache)
        {
            dp[stp[i] + p.first][p.first] = p.second;
        }
    }

    ull ans = 0;
    for (auto &p : dp)
    {
        for (auto &q : p.second)
        {
            // printf("  %d에서 %d만큼 차이가 나는 계단을 만들 수 있는 경우의 수: %d\n", p.first, q.first, q.second);
            ans = (ans + q.second);
            while (ans >= MOD)
            {
                ans -= MOD;
            }
        }
    }

    cout << ans << '\n';
}
