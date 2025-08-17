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

map<int, int> xmap;
map<int, int> ymap;

int X(int rx)
{
    if (xmap.find(rx) != xmap.end())
        return xmap[rx];
    return xmap[rx] = xmap.size();
}

int Y(int rx)
{
    if (ymap.find(rx) != ymap.end())
        return ymap[rx];
    return ymap[rx] = ymap.size();
}

int xcnt[100005] = {
    0,
};
int ycnt[100005] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        int x, y;
        cin >> x >> y;
        xcnt[X(x)]++;
        ycnt[Y(y)]++;
    }

    int ans = 0;
    for (int i = 0; i < xmap.size(); i++)
    {
        if (xcnt[i] >= 2)
            ans++;
    }
    for (int i = 0; i < ymap.size(); i++)
    {
        if (ycnt[i] >= 2)
            ans++;
    }

    cout << ans;
}
