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
#define itn int

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dp[505][505][2];
// dp[first bukkit][second bukkit][hwo]

int get_[4];

// 0 is A , 1  is B
bool getAWin(int fb, int sb, bool who)
{
    if (dp[fb][sb][who] != -1)
        return dp[fb][sb][who];

    for (int i = 0; i < 3; i++)
    { // 첫번째꺼를 먹는다
        if (get_[i] <= fb && !getAWin(fb - get_[i], sb, !who))
        {
            dp[fb][sb][who] = 1;
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    { // 두번째꺼를 먹는다
        if (get_[i] <= sb && !getAWin(fb, sb - get_[i], !who))
        {
            dp[fb][sb][who] = 1;
            return true;
        }
    }

    dp[fb][sb][who] = 0;
    return false;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> get_[0] >> get_[1] >> get_[2];
    for (int i = 0; i < 5; i++)
    {
        memset(dp, -1, sizeof(dp));
        int f, s;
        cin >> f >> s;
        if (getAWin(f, s, 0))
            cout << "A\n";
        else
            cout << "B\n";
    }
}