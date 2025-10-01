#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <cstring>

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;
typedef uint16_t cint;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

cint needLiter[1005][1005];

cint n; // 급유지
cint k; // 최대 연료 충전 수

struct Pos
{
    cint x;
    cint y;
};

vector<Pos> poses;

int calc_dist(cint x, cint y, cint xx, cint yy)
{
    int a = x - xx;
    int b = y - yy;
    double sqd = sqrt(a * a + b * b);
    double xyxy = sqd - (double)(((int)(sqd / 10)) * 10);
    if (xyxy)
        sqd += 10 - xyxy;
    return sqd;
}

bool bfs(cint maxD)
{
    queue<int> q;
    q.push(0);
    bool visited[1005];
    visited[0] = true;
    memset(visited, 0, n + 2);

    cint t = 0;
    while (!q.empty())
    {
        if (t > k + 1)
            return false;
        unsigned long qs = q.size();
        while (qs--)
        {
            int qf = q.front();
            q.pop();

            if (qf == poses.size() - 1)
            {
                return true;
            }

            for (int i = 1; i < poses.size(); i++)
            {
                // qf -> i
                if (i == qf)
                    continue;
                int nLiter = needLiter[i][qf];
                if (nLiter > maxD)
                    continue;
                if (visited[i])
                    continue;
                visited[i] = true;
                q.push(i);
            }
        }
        t++;
    }

    return false;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    poses.push_back({0, 0});

    for (int i = 0; i < n; i++)
    {
        Pos p;
        cin >> p.x >> p.y;
        poses.push_back(p);
    }

    poses.push_back({10000, 10000});

    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            if (i == j)
                continue;
            if (i < j)
                needLiter[i][j] = calc_dist(poses[i].x, poses[i].y, poses[j].x, poses[j].y) / 10;
            else
                needLiter[i][j] = needLiter[j][i];
        }
    }

    cint l = 0;
    cint h = 1415;
    cint lastAble = 0;

    while (l <= h)
    {
        cint m = (int)(((int)l + (int)h) / (int)2);
        bool x = bfs(m);
        if (x)
        {
            h = m - 1;
            lastAble = m;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << lastAble;
}