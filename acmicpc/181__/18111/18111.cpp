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

struct Pos
{
    int x;
    int y;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, w, inv;
    cin >> h >> w >> inv;
    int v[500][500];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> v[i][j];

    int ans = INT_MAX;
    int ansH = 0;
    for (int i = 0; i <= 256; i++)
    {
        int t = 0;
        int pick = 0;
        int place = 0;
        for (int j = 0; j < h; j++)
        {
            for (int k = 0; k < w; k++)
            {
                int h = v[j][k] - i;
                if (h > 0)
                { // 높은거 > 기준
                    t += h * 2;
                    pick += h;
                }
                else if (h < 0)
                { // 기준보다 낮음 => 설치
                    t -= h;
                    place -= h;
                }
            }
        }

        if (pick + inv >= place && ans >= t)
        {
            ans = t;
            ansH = i;
        }
    }

    cout << ans << " " << ansH;
}
