#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <numbers>
#include <cassert>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dist[505];

struct Path
{
    int from;
    int to;
    int tch;
};

void rmain()
{
    vector<Path> path;
    int n, m, b;
    cin >> n >> m >> b;
    for (int i = 0; i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        path.push_back({s, e, t});
        path.push_back({e, s, t});
    }

    for (int i = 0; i < b; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        path.push_back({s, e, -t});
    }

    memset(dist, 0, sizeof(dist));

    bool cng = 0;
    for (int i = 0; i < n; i++)
    {
        cng = 0;
        for (int j = 0; j < path.size(); j++)
        {
            if (dist[path[j].to] > dist[path[j].from] + path[j].tch)
            {
                dist[path[j].to] = dist[path[j].from] + path[j].tch;
                cng = 1;
            }
        }
    }

    cout << (cng ? "YES" : "NO")
         << "\n";
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    int f;
    cin >> f;
    while (f--)
        rmain();
}