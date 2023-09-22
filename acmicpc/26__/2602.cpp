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

string durumari;
string bridge[3];

int dp[3][105][25];

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> durumari >> bridge[0] >> bridge[1];

    int bs = bridge[0].size();
    int ds = durumari.size();

    for (int i = 0; i < bs; i++)
    {
        if (bridge[0][i] == durumari[0])
            dp[0][i][0] = 1;
        if (bridge[1][i] == durumari[0])
            dp[1][i][0] = 1;
    }

    for (int i = 0; i < bs; i++)
    {
        for (int j = 1; j < ds; j++)
        {
            if (bridge[0][i] == durumari[j])
            {
                int cnt = 0;
                for (int k = 0; k < i; k++)
                {
                    if (dp[1][k][j - 1] != 0)
                        cnt += dp[1][k][j - 1];
                    dp[0][i][j] = cnt;
                }
            }

            if (bridge[1][i] == durumari[j])
            {
                int cnt = 0;
                for (int k = 0; k < i; k++)
                {
                    if (dp[0][k][j - 1] != 0)
                        cnt += dp[0][k][j - 1];
                    dp[1][i][j] = cnt;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < bs; i++)
    {
        ans += dp[0][i][ds - 1];
        ans += dp[1][i][ds - 1];
    }

    cout << ans;
}