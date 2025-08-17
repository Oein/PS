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

int n;
vector<int> v;

int calcAble(int st, int ed)
{
    // calc
    int lastV = v[st];
    for (int i = st + 2; i <= ed; i += 2)
    {
        if (v[i] > lastV)
        {
            lastV = v[i];
        }
        else
        {
            // printf(" > UNAV AT %d (%d > %d)\n", i, v[i], lastV);
            return 0;
        }
    }

    lastV = v[st + 1];
    for (int i = st + 3; i <= ed; i += 2)
    {
        if (v[i] < lastV)
        {
            lastV = v[i];
        }
        else
        {
            // printf(" > UNAV AT %d (%d < %d)\n", i, v[i], lastV);
            return 0;
        }
    }

    return ed - st + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    if (n == 1 || n == 2)
    {
        cout << n;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int ans = 2;

    for (int st = 0; st <= n; st++)
    {
        for (int ed = st + ans; ed < n; ed++)
        {
            const int v = calcAble(st, ed);
            // printf("st: %d, ed: %d, v: %d\n", st, ed, v);
            ans = max(ans, v);
        }
    }

    cout << ans;
}
