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

void rmain()
{
    long long a, b;
    cin >> a >> b;

    long long t = a + b, c = (t / 4) + (t % 4 ? 1 : 0), diff = abs(a - b);
    if (diff > c * 2)
    {
        printf("-1\n");
        return;
    }
    if (a < c || b < c)
    {
        printf("-1\n");
        return;
    }
    printf("%lld\n", c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        rmain();
    }
}
