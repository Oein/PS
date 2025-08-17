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

int n, m, k;

// s 역에서 d 역으로 이동함.
// 시간은 st분에 출발 dt분에 도착함.
struct Train
{
    int st, d, dt;
};

// key: s
// value: (st, (d, dt))
// map<int, vector<int, pair<int, int>>> trains;

map<int, vector<pair<int, pair<int, int>>>> trains;

void rmain()
{
    // from 역에서 k역까지 가야함.
    int from, at;
    cin >> from >> at;

    // pair<시간, 역>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({at, from});

    while (!pq.empty())
    {
        auto qf = pq.top();
        int time = qf.first;
        int station = qf.second;
        // printf("time: %d, station: %d\n", time, station);
        pq.pop();

        if (station == k)
        {
            cout << time << '\n';
            return;
        }

        // 이진 탐색으로 train.first >= time인 것을 찾아야 함.
        // int l = 0;
        // int r = trains[station].size() - 1;
        // int ableFrom = -1;
        // while (l < r)
        // {
        //     int mid = (l + r) / 2;
        //     if (trains[station][mid].first >= time)
        //         ableFrom = min(ableFrom, mid);
        //     if (trains[station][mid].first < time)
        //     {
        //         l = mid + 1;
        //     }
        //     else
        //     {
        //         r = mid;
        //     }
        // }

        set<int> gotST;

        for (int i = 0; i < trains[station].size(); i++)
        {
            int nextStation = trains[station][i].second.first;
            int arrivingAt = trains[station][i].first;

            if (time <= arrivingAt)
            {
                if (gotST.find(nextStation) != gotST.end())
                    continue;

                gotST.insert(nextStation);
                pq.push({trains[station][i].second.second, nextStation});
            }
        }
    }

    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    int q;
    cin >> q;

    for (int i = 0; i < m; i++)
    {
        int s, st, d, dt;
        cin >> s >> st >> d >> dt;
        trains[s].push_back({st, {d, dt}});
    }

    // loop in trains with key
    for (auto &x : trains)
    {
        sort(x.second.begin(), x.second.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
             { return a.second.second < b.second.second; });
        // cout << "======= " << x.first << " =======\n";
        // for (auto &y : x.second)
        // {
        //     cout << y.first << ' ' << y.second.first << ' ' << y.second.second << '\n';
        // }
    }

    while (q--)
    {
        rmain();
    }
}
