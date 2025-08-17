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

vector<ull> v;
vector<ull> dp;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dp.push_back(0);
    v.push_back(0);
    ull ldt = 0;
    for (int i = 0; i < n; i++)
    {
        ull d;
        cin >> d;
        v.push_back(d);
        ldt += d;
        dp.push_back(ldt);
    }

    for (int i = 2; i <= n; i++)
    {
        // 한명만 처리할지
        // 두명 같이 처리할지 선택

        // 그냥 이번 단계에서 한명 처리
        dp[i] = dp[i - 1] + v[i];
        dp[i] = min(dp[i], dp[i - 2] + max(v[i], v[i - 1]));
    }
    cout << dp[n];
}
