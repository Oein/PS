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

vector<int> adj[10001];
bool visited[10001];

int bfs(int cur)
{
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(cur);
    visited[cur] = true;

    int cnt = 1;
    while (!q.empty())
    {
        int qf = q.front();
        q.pop();

        for (int i = 0; i < adj[qf].size(); i++)
        {
            int next = adj[qf][i];
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    int maxv = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int ret = bfs(i) + 1;
        if (ret > maxv)
        {
            maxv = ret;
            ans.clear();
            ans.push_back(i);
        }
        else if (ret == maxv)
        {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
