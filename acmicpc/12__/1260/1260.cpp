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

struct Pos
{
    int x;
    int y;
};

vector<int> path[1005];

int n, m, v;

bool visited[1005];

void dfs(int now)
{
    cout << now << " ";
    for (auto x : path[now])
    {
        if (!visited[x])
        {
            visited[x] = true;
            dfs(x);
        }
    }
}

bool visited2[1005];
void bfs()
{
    visited2[v] = true;
    queue<int> q;
    q.push(v);

    while (!q.empty())
    {
        int qn = q.front();
        q.pop();

        cout << qn << " ";
        for (auto x : path[qn])
        {
            if (!visited2[x])
            {
                visited2[x] = 1;
                q.push(x);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        sort(path[i].begin(), path[i].end());

    visited[v] = true;
    dfs(v);
    cout << "\n";
    bfs();
}
