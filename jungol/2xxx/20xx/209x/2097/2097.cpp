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
int visited[105];
int t[105][105];
int from[105];

int n, end_sub;

struct QData
{
    int now;
    int time;
};

struct QDataC
{
    bool operator()(const QData &a, const QData &b) const
    {
        return a.time > b.time;
    }
};

int main()
{
    memset(visited, 10001, sizeof(visited));
    cin.tie(0);
    cout.tie(0);
    cin >> n >> end_sub;
    visited[0] = -1;
    end_sub--;
    from[0] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> t[i][j];
        }
    }

    priority_queue<QData, vector<QData>, QDataC> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        QData qf = pq.top();
        pq.pop();

        if (qf.now == end_sub)
        {
            cout << qf.time << "\n";
            stack<int> s;
            s.push(end_sub);

            int now = end_sub;
            while (now != 0)
            {
                s.push(from[now]);
                now = from[now];
            }
            while (!s.empty())
            {
                cout << s.top() + 1 << " ";
                s.pop();
            }
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (qf.now == i)
                continue;
            if (visited[i] < qf.time + t[qf.now][i])
                continue;
            // cout << qf.now << " -> " << i << "\n";
            pq.push({i, qf.time + t[qf.now][i]});
            visited[i] = qf.time + t[qf.now][i];
            from[i] = qf.now;
        }
    }
}