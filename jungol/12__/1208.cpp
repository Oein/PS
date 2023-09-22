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

int p;

struct Road
{
    int to;
    int need;
};

int visited[55];

int road[55][55];
int added[30];

const int zx3f_ = 1061109567;

struct QData
{
    int where;
    int need;
    char from;
};

struct QData_comp
{
    bool operator()(const QData &a, const QData &b) const
    {
        return a.need > b.need;
    }
};

priority_queue<QData, vector<QData>, QData_comp>
    pq;

int main()
{
    cin.tie(0);
    cout.tie(0);

    memset(road, 0x3f, sizeof(road));
    memset(visited, 0x3f, sizeof(visited));

    cin >> p;
    for (int i = 0; i < p; i++)
    {
        char a, b;
        int an, bn, c;
        cin >> a >> b >> c;

        if (a >= 'a')
            a -= 6;
        a -= 'A';

        if (b >= 'a')
            b -= 6;
        b -= 'A';

        an = a;
        bn = b;

        // cout << (char)(a + 'A') << " : " << an << "\n";
        // cout << (char)(b + 'A') << " : " << bn << "\n";

        road[an][bn] = min(road[an][bn], c);
        road[bn][an] = min(road[bn][an], c);

        if (a + 'A' <= 'Y' && added[an] == false)
        {
            added[an] = 1;
            visited[an] = 0;
            pq.push({an, 0, (char)(a + 'A')});
        }

        if (b + 'A' <= 'Y' && added[bn] == false)
        {
            added[bn] = 1;
            visited[bn] = 0;
            pq.push({bn, 0, (char)(b + 'A')});
        }
    }

    while (!pq.empty())
    {
        QData qf = pq.top();
        pq.pop();

        // cout << "W : " << qf.where << " N : " << qf.need << " F : " << qf.from << "\n";

        // Z
        if (qf.where == 25)
        {
            cout << qf.from << " " << qf.need;
            return 0;
        }

        for (int i = 0; i < 55; i++)
        {
            if (i == qf.where)
                continue;
            // cout << qf.where << " -> " << i << "\n";
            if (road[qf.where][i] == zx3f_)
                continue;
            if (visited[i] <= qf.need + road[qf.where][i])
                continue;
            // cout << road[qf.where][i] << "\n";
            // cout << qf.where << " -> " << i << "\n";
            visited[i] = qf.need + road[qf.where][i];
            pq.push({i, visited[i], qf.from});
        }
    }
}