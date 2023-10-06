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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;

    int ans = 0;
    while (a < b)
    {
        if (b % 2 == 0)
        {
            b /= 2;
            ans++;
        }
        else
        {
            if (b % 10 == 1)
            {
                b /= 10;
                ans++;
            }
            else
            {
                cout << -1;
                return 0;
            }
        }
    }

    if (a == b)
        cout << ans + 1;
    else
        cout << -1;
}
