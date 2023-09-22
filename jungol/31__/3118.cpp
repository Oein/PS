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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;

struct Path
{
    int to;
    i16 need;
};

struct QData
{
    int where;
    int need;
};

struct QData_comp
{
    bool operator()(const QData &a, const QData &b) const
    {
        return a.need > b.need;
    }
};

vector<Path>
    paths[100005];

int visited[100005];

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    fill(visited, visited + n + 1, 2000000000);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        i16 c;
        cin >> a >> b >> c;
        paths[a].push_back({b, c});
    }

    priority_queue<QData, vector<QData>, QData_comp> pq;

    pq.push({1, 0});
    visited[1] = 0;

    while (!pq.empty())
    {
        QData qf = pq.top();
        pq.pop();

        if (qf.where == n)
        {
            cout << qf.need;
            return 0;
        }

        for (Path to : paths[qf.where])
        {
            if (visited[to.to] > qf.need + to.need)
            {
                visited[to.to] = qf.need + to.need;

                pq.push({to.to, visited[to.to]});
            }
        }
    }
}