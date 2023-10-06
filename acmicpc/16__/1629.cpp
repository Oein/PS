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

ll a, b, c;

ll pow(ll x)
{
    if (x == 1)
        return a % c;
    ll t = pow(x / 2);
    if (x % 2 == 0)
        return t * t % c;
    else
        return t * t % c * a % c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    cout << pow(b) % c;
}
