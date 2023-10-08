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
    int n, m;
    cin >> n >> m;
    vector<int> x;
    while (n--)
    {
        int y;
        cin >> y;
        x.push_back(y);
    }
    sort(x.begin(), x.end());
    int ans = 0;
    for (int sel1 = 0; sel1 < x.size(); sel1++)
        for (int sel2 = sel1 + 1; sel2 < x.size(); sel2++)
            for (int sel3 = sel2 + 1; sel3 < x.size(); sel3++)
            {
                int sum = x[sel1] + x[sel2] + x[sel3];
                if (sum > m)
                    continue;
                if (abs(m - ans) > abs(m - sum))
                    ans = sum;
            }

    cout << ans;
}
