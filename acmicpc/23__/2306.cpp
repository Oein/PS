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

string str;

/*
 dp?

 "at"   or "gc"   = correct dna
 "a??t" or "g??c" = correct dna

 max 500 len
  // (n^2)logn


*/

int dp_memo[505][505];

int dp(int st, int ed)
{
    if (st >= ed)
        return 0;

    if (dp_memo[st][ed] != -1)
        return dp_memo[st][ed];

    int ans = -1;

    for (int k = st; k < ed; k++)
    {
        ans = max(ans, dp(st, k) + dp(k + 1, ed));
    }

    if (str[st] == 'a' && str[ed] == 't')
        ans = max(ans, dp(st + 1, ed - 1) + 2);

    if (str[st] == 'g' && str[ed] == 'c')
        ans = max(ans, dp(st + 1, ed - 1) + 2);

    return dp_memo[st][ed] = ans;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> str;

    memset(dp_memo, -1, sizeof(dp_memo));

    cout << dp(0, str.size() - 1);
}