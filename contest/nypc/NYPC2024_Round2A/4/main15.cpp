#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

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
int8_t d[150005];
vector<int> adj[150005];
bool visited[150005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        d[i] -= '0';
        // cout << "WRITE AT " << i << " = " << d[i] << '\n';
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<string, int>> ans;

    for (int i = 0; i < m; i++)
    {
        memset(visited, 0, sizeof(visited));
        int s, e;
        cin >> s >> e;
        s--, e--;

        queue<pair<int, vector<int8_t>>> q;
        // cout << "S" << s << " : " << d[s] << '\n';
        q.push({s, {d[s]}});
        visited[s] = true;
        while (!q.empty())
        {
            auto qf = q.front();
            q.pop();

            int cur = qf.first;
            if (cur == e)
            {
                string str = "";
                for (int i = 0; i < qf.second.size(); i++)
                {
                    // printf("%d Became %s\n", qf.second[i], to_string((char)qf.second[i]).c_str());
                    str += to_string(qf.second[i]);
                }
                ans.push_back({str, i});
                // cout << "SZ: " << qf.second.size() << '\n';
                break;
            }

            for (int next : adj[cur])
            {
                if (visited[next])
                    continue;
                visited[next] = true;
                qf.second.push_back(d[next]);
                // for (int i = 0; i < qf.second.size(); i++)
                //     cout << qf.second[i] << ' ';
                // cout << '\n';
                q.push({next, qf.second});
                qf.second.pop_back();
            }
        }
    }

    sort(ans.begin(), ans.end(), [](pair<string, int> a, pair<string, int> b)
         {
            if(a.first.size() != b.first.size())
                return a.first.size() < b.first.size();
                if(a.first == b.first) return a.second < b.second;
                return a.first < b.first; });

    for (auto a : ans)
    {
        cout << a.second + 1 << '\n';
    }
}
