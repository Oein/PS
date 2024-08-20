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
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct XY
{
    int x;
    int y;

    bool operator==(const XY &other) const
    {
        return (x == other.x) && (y == other.y);
    }
};

struct QData
{
    int x;
    int y;
    int money;
};

struct compare
{
    bool operator()(const QData &s1, const QData &s2)
    {
        return s1.money > s2.money;
    }
};

int n, moreMoney, already_placed;

int board[55][55];
bool visited[55][55];
XY from[55][55];

XY st;
XY ed;

int main()
{
    cin.tie(0);
    cout.tie(0);

    queue<XY> q;
    cin >> n >> st.y >> st.x >> ed.y >> ed.x >> moreMoney >> already_placed;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[j][i] = 0;
        }
    }
    moreMoney--;
    visited[st.y][st.x] = 1;
    from[st.y][st.x] = {st.x, st.y};

    for (int i = 0; i < already_placed; i++)
    {
        int turns;
        cin >> turns;
        turns--;
        XY last;
        cin >> last.y >> last.x;
        board[last.y][last.x] = 1;
        for (int j = 0; j < turns; j++)
        {
            int x_, y_;
            cin >> y_ >> x_;
            if (last.x == x_)
            {
                for (int k = min(y_, last.y); k <= max(y_, last.y); k++)
                {
                    board[k][x_] = moreMoney;
                }
            }
            else
            {
                for (int k = min(x_, last.x); k <= max(x_, last.x); k++)
                {
                    board[y_][k] = moreMoney;
                }
            }

            last.x = x_;
            last.y = y_;
        }
    }

    priority_queue<QData, vector<QData>, compare> pq;
    QData tmp_ = {
        st.x,
        st.y,
        board[st.y][st.x] + 1};
    pq.push(tmp_);

    while (!pq.empty())
    {
        QData qf = pq.top();
        pq.pop();

        if (qf.x == ed.x && qf.y == ed.y)
        {
            XY now_ = ed;
            XY tmp_ = from[now_.y][now_.x];
            stack<XY> path;

            int changing = 0;

            if (now_.x != tmp_.x)
                changing = 1;

            while (!(now_ == st))
            {
                int ngchanging_ = 1;
                if (from[now_.y][now_.x].x != now_.x)
                    ngchanging_ = 0;

                if (changing != ngchanging_)
                {
                    path.push(now_);
                }

                changing = ngchanging_;
                // cout << from[now_.y][now_.x].x << " , " << from[now_.y][now_.x].y << "\n";
                now_ = from[now_.y][now_.x];
            }
            cout << qf.money << "\n";
            cout << path.size() + 1 << " ";
            cout << st.y << " " << st.x << " ";
            while (!path.empty())
            {
                cout << path.top().y << " " << path.top().x << " ";
                path.pop();
            }
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            QData nq = qf;
            nq.x += dx[i];
            nq.y += dy[i];
            nq.money += board[nq.y][nq.x] + 1;

            if (nq.x < 1 || nq.y < 1 || nq.x > n || nq.y > n)
                continue;
            if (visited[nq.y][nq.x])
                continue;

            from[nq.y][nq.x] = {qf.x, qf.y};
            visited[nq.y][nq.x] = 1;

            pq.push(nq);
        }
    }
}