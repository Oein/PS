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

void hanoi(int n, int a, int b, int c)
{
    if (n == 1)
    {
        cout << a << " " << c << "\n";
        return;
    }
    hanoi(n - 1, a, c, b);
    hanoi(1, a, b, c);
    hanoi(n - 1, b, a, c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int cnt = 1;
    for (int i = 0; i < n; i++)
        cnt *= 2;
    cnt -= 1;
    cout << cnt << "\n";
    hanoi(n, 1, 2, 3);
}
