/*

s ~ e 까지 n개가 있다고 알려줌


못 만들면 NONE을 출력

or

- 는 없음
# 은 있음으로 출력

*/

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

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int k, n;

struct Path
{
    int from;
    int to;
    int need;
};

vector<Path> paths;
ll dist[45];

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;

    while (n--)
    {
        int s, e, d;
        cin >> s >> e >> d;

        paths.push_back({s - 1, e, d});
        paths.push_back({e, s - 1, -d});
    }

    for (int i = 0; i < k; i++)
    {
        paths.push_back({i, i + 1, 1});
        paths.push_back({i + 1, i, 0});
    }

    for (int i = 1; i <= k; i++)
        dist[i] = 1000000007;

    for (int i = 0; i < k; i++)
    {
        for (Path e : paths)
        {
            dist[e.to] = min(dist[e.to], dist[e.from] + e.need);
        }
    }

    bool ok = 1;

    for (Path e : paths)
    {
        if (dist[e.to] > dist[e.from] + e.need)
        {
            ok = 0;
        }
    }

    if (ok)
    {
        for (int i = 1; i <= k; i++)
        {
            // cout << "Dist[" << i << "] = " << dist[i] << "\n";
            if (dist[i - 1] < dist[i])
                cout << "#";
            else
                cout << "-";
        }
    }
    else
    {
        cout << "NONE";
    }
}