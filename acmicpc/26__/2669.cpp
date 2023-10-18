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

bool board[105][105];

void x()
{
    int xst, yst, xed, yed;
    cin >> xst >> yst >> xed >> yed;
    for (int i = xst; i < xed; i++)
        for (int j = yst; j < yed; j++)
            board[i][j] = true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 4; i++)
        x();

    int ans = 0;
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 105; j++)
            if (board[i][j])
                ans++;
    cout << ans;
}
