#include <bits/stdc++.h>
using namespace std;

int d[100001];
int parent_idx[100001];
map<int, int> num_as_index;
stack<int> st;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int k;

    cin >> n >> k;

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        d[i] = 0;
        for (int j = 0; j < k; j++)
        {
            d[i] <<= 1;
            d[i] |= (s[j] - '0');
        }
        num_as_index[d[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int tmpx = d[i] ^ (1 << j);

            auto it = num_as_index.find(tmpx);

            if (it != num_as_index.end())
            {
                adj[i].push_back(it->second);
            }
        }
    }

    memset(parent_idx, -1, sizeof(parent_idx));

    queue<int> q;
    parent_idx[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (parent_idx[v] == -1)
            {
                parent_idx[v] = u;
                q.push(v);
            }
        }
    }

    int m;
    cin >> m;

    while (m--)
    {
        int to;
        cin >> to;
        if (parent_idx[to] == -1)
        {
            cout << "-1\n";
            continue;
        }

        for (int i = to; i != 1; i = parent_idx[i])
            st.push(i);

        cout << "1 ";
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }

        cout << "\n";
    }
}