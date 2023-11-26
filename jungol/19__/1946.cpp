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

int n, m;

pair<set<int>, set<int>> deg[1005]; // deg[i] = i번째 가수를 indeg로 쓰는 놈들
int elemCnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    elemCnt = n;

    for (int i = 0; i < m; i++)
    {
        int cnt, fr;
        cin >> cnt >> fr;
        for (int j = 0; j < cnt - 1; j++)
        {
            int to;
            cin >> to;
            deg[fr].second.insert(to);
            deg[to].first.insert(fr);
            // cout << fr << " -> " << to << "\n";
            fr = to;
        }

        // cout << "====\n";
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (deg[i].first.size() == 0)
            q.push(i);
    }

    vector<int> ans;

    while (elemCnt && !q.empty())
    {
        int qf = q.front();
        q.pop();

        ans.push_back(qf);

        elemCnt--;

        // cout << "Handle " << qf << "\n";

        for (auto x : deg[qf].second)
        {
            deg[x].first.erase(qf);
            // printf("deg[%d].first.size() == %d\n", x, deg[x].first.size());
            if (deg[x].first.size() == 0)
            {
                q.push(x);
                // cout << "Append " << x;
            }
        }
    }

    if (elemCnt)
        cout << 0;
    else
    {
        for (auto x : ans)
            cout << x << "\n";
    }
}
