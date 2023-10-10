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
vector<int> adj[1005];
int visited[1005];
int wkon = 1;

void tryNode(int st)
{
    if (visited[st] != 0)
        return;
    queue<int> q;
    q.push(st);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (visited[cur] != 0)
            continue;
        visited[cur] = wkon;
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if (visited[next] == 0)
                q.push(next);
        }
    }
    wkon++;
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        tryNode(i);
    cout << wkon - 1;
}
