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

int n;
string str;

// 나중에 track 할때 다른 데이터가 필요 할 수 있으니까 우선 Struct로...
struct DPData
{
    int need;
    int mhei;
    int spliter = 0;
};

DPData dp[105][105];

DPData dpFunction(int s, int e)
{
    if (s > e)
        return {0, 0};

    if (dp[s][e].need != -1)
        return dp[s][e];

    dp[s][e].need = 0;

    int ans = 1000000010;
    int anh = 0;
    int anp = 0;

    for (int i = s + 1; i <= e; i += 2)
    {
        if (str[s] != str[i])
        {
            DPData l = dpFunction(s + 1, i - 1);
            DPData r = dpFunction(i + 1, e);

            int ditance = i - s;
            int ned = l.need + r.need + ditance + (l.mhei + 1) * 2;

            if (ans > ned)
            {
                ans = ned;
                anh = max(l.mhei + 1, r.mhei);
                anp = i;
            }
        }
    }

    return dp[s][e] = {ans, anh, anp};
}

void trace(int s, int e)
{
    if (s > e)
        return;

    cout << s + 1 << " " << dp[s][e].spliter + 1 << "\n";

    trace(s + 1, dp[s][e].spliter - 1);
    trace(dp[s][e].spliter + 1, e);
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> str;
    for (int i = 0; i < n; i++)
    {
        str[i] -= '0'; // for easy number
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = {-1, 0};
        }
    }

    cout << dpFunction(0, n - 1).need << "\n";
    trace(0, n - 1);
}