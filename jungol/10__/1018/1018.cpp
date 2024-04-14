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

int mnum(int a, int b, int c, int d)
{
    return 1000 * a + 100 * b + 10 * c + d;
}

bool isClockNum(int num)
{
    int a = num / 1000;
    int b = (num / 100) % 10;
    int c = (num / 10) % 10;
    int d = num % 10;
    vector<int> ables;
    ables.push_back(mnum(a, b, c, d));
    ables.push_back(mnum(b, c, d, a));
    ables.push_back(mnum(c, d, a, b));
    ables.push_back(mnum(d, a, b, c));
    sort(ables.begin(), ables.end());
    return ables[0] == num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> ables;
    ables.push_back(mnum(a, b, c, d));
    ables.push_back(mnum(b, c, d, a));
    ables.push_back(mnum(c, d, a, b));
    ables.push_back(mnum(d, a, b, c));
    sort(ables.begin(), ables.end());

    int clocknum = ables[0];

    int check = 1111;
    int cnt = 1;

    while (check != clocknum)
    {
        if (isClockNum(check))
            cnt++;
        check++;
    }

    cout << cnt;
}

/*

1111
1112
1113
1114
1115
1116
1117
1118
1119
1121
1122
*/