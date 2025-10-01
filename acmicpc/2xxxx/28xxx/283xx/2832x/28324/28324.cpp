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

int n;
vector<int> speeds;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        speeds.push_back(x);
    }

    int mxspeed = 0;
    ull ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        mxspeed++;
        if (speeds[i] < mxspeed)
            mxspeed = speeds[i];
        speeds[i] = mxspeed;
        ans += (ull)speeds[i];
    }
    cout << ans;
}
