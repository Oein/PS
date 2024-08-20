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

ull dx[1005] = {
    0,
};

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

    int n;
    cin >> n;
    dx[1] = 1;
    dx[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        dx[i] = ((dx[i - 2] * 2) % 10007 + dx[i - 1] % 10007) % 10007;
        // cout << i << " : " << dx[i] << "\n";
    }

    cout << dx[n] % 10007;
}
