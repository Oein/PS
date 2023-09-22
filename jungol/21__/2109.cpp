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
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

#define DEBUG_ if (false)

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m, x;
int visited[1005];
unordered_map<int, int> roads[1005];

struct QData
{
    int loc;
    int tim;
};

struct QData_comp
{
    bool operator()(const QData &a, const QData &b) const
    {
        return a.tim > b.tim;
    }
};

int main()
{
    cin.tie(0);
    DEBUG_ cout.tie(0);
    cin >> n >> m >> x;
    x--;
    for (int i = 0; i < m; i++)
    {
        int f, t, m;
        cin >> f >> t >> m;
        f--;
        t--;

        if (roads[f].find(t) == roads[f].end())
        {
            roads[f][t] = m;
        }
        else
        {
            roads[f][t] = min(roads[f][t], m);
        }
    }

    int maxt = 0;

    for (int i = 0; i < n; i++)
    {
        DEBUG_ cout << "------N world-------\n";
        priority_queue<QData, vector<QData>, QData_comp> pq;
        memset(visited, 0x3f, sizeof(visited));
        pq.push({i,
                 0});

        visited[i] = 0;

        int go_cost = 0;
        while (!pq.empty())
        {
            QData qf = pq.top();
            pq.pop();

            DEBUG_ cout << "Calc on " << qf.loc << "\n";

            unordered_map<int, int>::iterator it;

            if (qf.loc == x)
            {
                DEBUG_ cout << "End with cost " << qf.tim << "\n";
                go_cost = qf.tim;
                break;
            }

            for (it = roads[qf.loc].begin(); it != roads[qf.loc].end(); it++)
            {
                int to = it->first;
                int nti = it->second;

                if (visited[to] <= nti + qf.tim)
                    continue;

                DEBUG_ cout << " - to " << to << " with cost " << nti << "\n";

                pq.push({
                    to,
                    nti + qf.tim,
                });
                visited[to] = nti + qf.tim;
            }
        }

        int return_cost = 0;

        DEBUG_ cout << "-- Calc return cost-- "
                    << "\n";

        priority_queue<QData, vector<QData>, QData_comp> pqx;
        memset(visited, 0x3f, sizeof(visited));
        pqx.push({x,
                  0});

        visited[x] = 0;

        while (!pqx.empty())
        {
            QData qf = pqx.top();
            pqx.pop();

            DEBUG_ cout << "Calc on " << qf.loc << "\n";

            unordered_map<int, int>::iterator it;

            if (qf.loc == i)
            {
                return_cost = qf.tim;
                break;
            }

            for (it = roads[qf.loc].begin(); it != roads[qf.loc].end(); it++)
            {
                int to = it->first;
                int nti = it->second;

                DEBUG_ cout << "NC " << nti + qf.tim << "\n";
                DEBUG_ cout << "OC " << visited[to] << "\n";

                if (visited[to] <= nti + qf.tim)
                    continue;

                DEBUG_ cout << " - to " << to << "\n";

                pqx.push({
                    to,
                    nti + qf.tim,
                });
                visited[to] = nti + qf.tim;
            }
        }

        DEBUG_ cout << "G " << go_cost << " R " << return_cost << "\n";

        maxt = max(maxt, go_cost + return_cost);
    }

    cout << maxt;
}