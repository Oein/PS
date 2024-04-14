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

bool saeroUsed[15] = {
    0,
};
int saero[15] = {
    0,
};

int ans = 0;
int n;

void dfs(int row)
{
    if (row == n)
    {
        ans++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (saeroUsed[col])
            continue;

        bool isPossible = true;
        for (int i = 0; i < row; i++)
        {
            if (abs(row - i) == abs(col - saero[i]))
            {
                isPossible = false;
                break;
            }
        }

        if (isPossible)
        {
            saeroUsed[col] = true;
            saero[row] = col;
            dfs(row + 1);
            saeroUsed[col] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

        cin >> n;

    dfs(0);
    cout << ans;
}
