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

vector<string> v;
bool enable[30] = {
    0,
};
int dfs(int x, int y)
{
    int mx = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if (nx < 0 || ny < 0 || nx >= v.size() || ny >= v[0].size())
            continue;
        if (enable[v[nx][ny]])
            continue;

        enable[v[nx][ny]] = true;
        mx = max(mx, dfs(nx, ny));
        enable[v[nx][ny]] = false;
    }

    return mx + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < x.size(); j++)
            x[j] -= 'A';
        v.push_back(x);
    }

    enable[v[0][0]] = true;
    cout << dfs(0, 0);
}
