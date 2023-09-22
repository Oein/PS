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

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const int maxn = 21;
const int INF = 2100000000;

const bool debug = false;

int n, m, visitedT = 1;
vector<int> path[22];

int cnt[22];
int visited[1 << 22];

// for output
int from[1 << 22];
int shoot[1 << 22];

struct QData
{
    int monkeys; // bit
};

queue<QData> q;
void qpush(QData d, int prev, int shooted)
{
    if (visited[d.monkeys] == visitedT)
        return;

    from[d.monkeys] = prev;
    shoot[d.monkeys] = shooted;
    visited[d.monkeys] = visitedT;

    q.push(d);
}

int mainLoop()
{
    while (!q.empty())
        q.pop();
    scanf(" %d %d", &n, &m);

    if (n == 0 && m == 0)
        return 0;

    for (int i = 0; i <= n; i++)
    {
        path[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        path[a].push_back(b);
        path[b].push_back(a);
    }

    if (m != n - 1)
    {
        cout << "Impossible\n";
        return 2;
    }

    q.push({(1 << n) - 1});

    int t = 0;
    while (!q.empty())
    {
        unsigned long qs = q.size();

        if (debug)
            cout << "------- " << t << " -------\n";

        while (qs--)
        {
            QData qf = q.front();
            int state = qf.monkeys;

            if (state == 0)
            {
                cout << t << ": ";

                stack<int> outs;

                int now = 0;
                while (now != (1 << n) - 1)
                {
                    outs.push(shoot[now]);
                    now = from[now];
                }

                while (!outs.empty())
                {
                    cout << outs.top() << " ";
                    outs.pop();
                }

                cout << "\n";

                return 2;
            }

            int new_state = 0;
            q.pop();

            fill(cnt, cnt + n, 0);

            // count
            for (int i = 0; i < n; i++)
            {
                if (!(state & (1 << i)))
                {
                    if (debug)
                        cout << "skip cnt : " << i << "\n";
                    continue;
                }

                if (debug)
                    cout << "path[" << i << "].size() = " << path[i].size() << "\n";

                for (int j = 0; j < path[i].size(); j++)
                {
                    int new_loc = path[i][j];

                    if (debug)
                        cout << "NEW LOC : " << new_loc << "\n";

                    cnt[new_loc]++;
                    new_state |= (1 << new_loc);
                }
            }

            if (debug)
            {
                cout << "///////////\n";
                cout << "/// Cnt ///\n";
                for (int i = 0; i < n; i++)
                {
                    cout << cnt[i] << " ";
                }
                cout << "\n";

                cout << "State : " << state << "\n";
                cout << "new state : " << new_state << "\n";
            }

            // shoot
            for (int i = 0; i < n; i++)
            {
                int next_state = new_state;

                if (!(state & (1 << i)))
                    continue;

                for (int j = 0; j < path[i].size(); j++)
                {
                    int new_loc = path[i][j];
                    if (cnt[new_loc] <= 1)
                        next_state &= ~(1 << new_loc);
                }

                if (debug)
                    cout << "Shoot : " << i << " Next state : " << next_state << "\n";
                qpush({next_state}, state, i);
            }
        }

        t++;
    }

    cout << "Impossible\n";
    return 2;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    while (mainLoop())
    {
        visitedT++;
        if (debug)
            cout << "=============================\n";
    }
}