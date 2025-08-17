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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    string x;
    cin >> n >> k >> x;
    int zeroRem = k;
    int oneRem = k;
    int oneCnt = 0;
    int zeroCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == '0')
        {
            zeroCnt++;
        }
        else
        {
            oneCnt++;
        }
    }

    if (zeroRem > zeroCnt)
    {
        oneRem += zeroRem - zeroCnt;
        zeroRem = zeroCnt;
    }
    if (oneRem > oneCnt)
    {
        zeroRem += oneRem - oneCnt;
        oneRem = oneCnt;
    }

    for (int i = 0; i < n; i++)
    {
        if (x[i] == '0')
        {
            if (zeroRem > 0)
                zeroRem--;
            else
                printf("0");
        }
        else
        {
            if (oneRem > 0)
                oneRem--;
            else
                printf("1");
        }
    }
}
