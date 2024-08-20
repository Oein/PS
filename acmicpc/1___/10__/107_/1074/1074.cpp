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

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

struct Pos
{
    int x;
    int y;
};

int calcsz(int wd)
{
    return wd * wd;
}

int pow2n(int n)
{
    return 1 << n;
}

int n, r, c; // r == y, c == x
int ans = 0;
int adx[4] = {0, 1, 0, 1};
int ady[4] = {0, 0, 1, 1};
void calc(int x, int y, int sz, int nowNum)
{
    if (x == c && y == r)
    {
        ans = nowNum;
        return;
    }
    if (sz == 1)
    {
        return;
    }
    int nsz = sz / 2;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + adx[i] * nsz;
        int ny = y + ady[i] * nsz;
        if (nx <= c && c < nx + nsz && ny <= r && r < ny + nsz)
        {
            calc(nx, ny, nsz, nowNum + i * calcsz(nsz));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r >> c;
    calc(0, 0, pow2n(n), 0);
    cout << ans;
}
