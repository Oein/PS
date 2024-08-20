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

vector<int> to;

int cycler[105] = {
    0,
};
int nowCyNum = 1;
int root = -1;
vector<bool> useableCycle;

int dfs(int x)
{
    if (x == -1)
        return -1;
    if (cycler[x] == nowCyNum)
    { // 돌아옴
        if (x != root)
        {
            useableCycle.push_back(false);
            return -1;
        }
        useableCycle.push_back(true);
        return 0;
    }
    cycler[x] = nowCyNum;
    int res = dfs(to[x]);
    if (res == -1)
        return -1;
    else
        return res + 1;
}

set<int> ans;
set<int> ansSet;
void rot(int x, bool isFirst = false)
{
    if (x == -1)
        return;
    if (x == root && !isFirst)
        return;
    ans.insert(x);
    rot(to[x]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    to.push_back(-1);
    useableCycle.push_back(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        to.push_back(x);
    }

    int cycleItemCnt = 0;

    vector<int> dfsx;

    for (int i = 1; i <= n; i++)
    {
        if (cycler[i] == 0 || ansSet.find(cycler[i]) == ansSet.end())
        {
            root = i;
            nowCyNum++;
            int res = dfs(i);
            // cout << "RES" << i << "W" << res << "\n";
            if (res != -1)
            {
                cycleItemCnt += res;
                dfsx.push_back(i);
                // cout << "ADD" << i << "W" << res << "\n";
                ansSet.insert(nowCyNum);
            }
        }
    }

    for (auto x : dfsx)
    {
        root = x;
        rot(x, true);
    }

    cout << ans.size() << "\n";

    for (auto x : ans)
        cout << x << "\n";
}
