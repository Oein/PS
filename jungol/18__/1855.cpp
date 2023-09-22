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

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, p, c;
int where[505];
int need[805][805];

interface Path
{
    int to;
    int cost;
};

vector<Path> paths[805];

interface QData
{
    int where;
    int cost;
};

interface QComp
{
    bool operator()(const QData &a, const QData &b) const
    {
        return a.cost > b.cost;
    }
};

void calc(int st)
{
    if (need[st][st] != zx3f)
        return;
    priority_queue<QData, vector<QData>, QComp> pq;

    need[st][st] = 0;
    pq.push({st, 0});

    while (!pq.empty())
    {
        QData qf = pq.top();
        pq.pop();

        for (Path p : paths[qf.where])
        {
            if (p.cost + qf.cost >= need[st][p.to])
            {
                continue;
            }

            need[st][p.to] = p.cost + qf.cost;
            pq.push({p.to, need[st][p.to]});
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> c;

    int mpn = 0;

    memset(need, 0x3f, sizeof(need));

    for (int i = 0; i < c; i++)
    {
        int f, t, c;
        cin >> f >> t >> c;

        mpn = max(mpn, f);
        mpn = max(mpn, t);

        paths[f].push_back({t, c});
        paths[t].push_back({f, c});
    }

    for (int i = 0; i < n; i++)
    {
        cin >> where[i];
        mpn = max(mpn, where[i]);
        calc(where[i]);
    }

    int rans = zx3f;
    // where to meet
    for (int i = 1; i <= mpn; i++)
    {
        int ans = 0;
        // who cost
        for (int j = 0; j < n; j++)
        {
            ans += need[where[j]][i];
        }
        rans = min(rans, ans);
    }

    cout << rans;
}