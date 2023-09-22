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

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, ans = 0;

struct Path
{
    int from;
    int to;
    int need;
};

vector<Path> paths;

int group[105];

int seek(int k)
{ // k 가 속한 그룹의 맨 꼭대기
    if (k == group[k])
        return k;
    return group[k] = seek(group[k]);
}

bool join(int x, int y, int c)
{
    x = seek(x), y = seek(y);
    // cout << "SEEK " << x << " , " << y << "\n";
    if (x == y)
        return 0;
    group[x] = y;
    ans += c;
    return 1;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        group[i] = i;
        for (int j = 0; j < n; j++)
        {
            int c;
            cin >> c;
            if (i < j)
            {
                paths.push_back({i, j, c});
            }
        }
    }

    sort(paths.begin(), paths.end(), [](Path &a, Path &b)
         { return a.need < b.need; });

    int needTjoin = n;

    for (Path &path : paths)
    {
        bool x = join(path.from, path.to, path.need);
        if (x)
        {
            needTjoin--;
        }

        if (needTjoin <= 1)
        {
            cout << ans;
            return 0;
        }
    }
}