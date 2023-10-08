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

int arr[15][15] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < 15; i++)
        arr[0][i] = i;
    for (int i = 1; i < 15; i++)
        for (int j = 1; j < 15; j++)
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        cout << arr[k][n] << "\n";
    }
}
