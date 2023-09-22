#include <bits/stdc++.h>
using namespace std;
vector<int> adj[2][100001];
bool visited[100001];
int n, M, X, k;

int dfs(int n)
{
    visited[n] = 1;
    int ret = 1;
    for (auto v : adj[k][n])
    {
        if (!visited[v])
            ret += dfs(v);
    }
    return ret;
}

int main()
{
    cin >> n >> M >> X;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }
    int U, V;
    U = n - dfs(X) + 1;
    k = 1;
    V = dfs(X);
    cout << V << " " << U;
}