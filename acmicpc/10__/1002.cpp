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

int rmain()
{
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double dist2 = abs(r1 - r2);

    if (dist == 0 && r1 == r2) // 원이 같음
        return -1;
    if (dist2 < dist && dist < r1 + r2) // 교점이 2개
        return 2;
    if (dist == r1 + r2 || dist == dist2) // 교점이 1개
        return 1;
    // 만나는 점이 없음
    if (r1 + r2 < dist || dist < dist2 || (dist == 0 && r1 != r2))
        return 0;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        cout << rmain() << "\n";
}
