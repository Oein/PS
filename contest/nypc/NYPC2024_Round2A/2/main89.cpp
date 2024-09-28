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

int n, m, q;

// 레이저는 m개 있음.

using Lazer = pair<pair<int, int>, pair<int, int>>;
set<int> saero_lazers;
set<int> garo_lazers;
// false이면 오른쪽 위로, true이면 오른쪽 아래로
using SLLazer = pair<bool, int>;
set<SLLazer> sl_lazers;

void rmain()
{
    // cout << "==================\n";
    int fromy, fromx, toy, tox;
    cin >> fromy >> fromx >> toy >> tox;
    // 세로 레이저 + 사선 레이저
    int a = min(fromx, tox);
    int b = max(fromx, tox);
    int c = min(fromy, toy);
    int d = max(fromy, toy);
    for (auto &lz : saero_lazers)
    {
        if (lz >= a && lz <= b)
        {
            cout << "0\n";
            return;
        }
    }
    for (auto &lz : garo_lazers)
    {
        if (lz >= c && lz <= d)
        {
            cout << "0\n";
            return;
        }
    }

    int froml = fromx - fromy + 1;
    int fromr = fromx + fromy - 1;
    int tol = tox - toy + 1;
    int tor = tox + toy - 1;

    // printf("SL %d ~ %d, %d ~ %d\n", froml, tol, fromr, tor);

    if (froml > tol)
    {
        swap(froml, tol);
    }
    if (fromr > tor)
    {
        swap(fromr, tor);
    }

    for (auto &lazer : sl_lazers)
    {
        if (lazer.first)
        {
            // 왼쪽 아래로감
            if (lazer.second >= froml && lazer.second <= tol)
            {
                cout << "0\n";
                return;
            }
        }
        else
        {
            if (lazer.second <= tor && lazer.second >= fromr)
            {
                cout << "0\n";
                return;
            }
        }
    }

    cout << "1\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        Lazer lazer = {{r1, c1}, {r2, c2}};
        if (r1 == r2)
        {
            garo_lazers.insert(r1);
        }
        else if (c1 == c2)
        {
            saero_lazers.insert(c1);
        }
        else
        {
            if (c1 > c2)
            {
                swap(c1, c2);
                swap(r1, r2);
            }
            // c1이 항상 왼쪽
            bool is_down = r1 < r2;
            // y = 0 일때의 x값
            int x = is_down ? c1 - r1 + 1 : c1 + r1 - 1;
            sl_lazers.insert({is_down, x});
        }
    }

    for (int i = 0; i < q; i++)
    {
        rmain();
    }
}
