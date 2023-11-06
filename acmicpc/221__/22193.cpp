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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b >> a >> b;

    // multiply a and b

    int aLen = a.length();
    int bLen = b.length();

    vector<int> result(aLen + bLen, 0);

    for (int i = aLen - 1; i >= 0; i--)
    {
        for (int j = bLen - 1; j >= 0; j--)
        {
            result[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        }
    }

    for (int i = aLen + bLen - 1; i > 0; i--)
    {
        result[i - 1] += result[i] / 10;
        result[i] %= 10;
    }

    bool isZero = true;

    for (int i = 0; i < aLen + bLen; i++)
    {
        if (result[i] != 0)
        {
            isZero = false;
        }
        if (!isZero)
            cout << result[i];
    }

    if (isZero)
        cout << 0;
}
