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

int initalL[13];

int divid[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
};

pair<int, int> idxToXY[] = {
    {0, 0},
    {1, 0},
    {2, 0},
    {0, 1},
    {1, 1},
    {2, 1},
    {0, 2},
    {1, 2},
    {2, 2},
};

int swap(int original, int originalX, int originalY, int swapX, int swapY)
{
    int originalIdx = 8 - (originalY * 3 + originalX);
    int swapIdx = 8 - (swapY * 3 + swapX);

    int originalNum = (original / divid[originalIdx]) % 10;
    int swapNum = (original / divid[swapIdx]) % 10;

    original -= originalNum * divid[originalIdx];
    original -= swapNum * divid[swapIdx];

    original += swapNum * divid[originalIdx];
    original += originalNum * divid[swapIdx];

    return original;
}

map<long long, int> visited;
map<long long, long long> path;

struct QData
{
    long long num;
    long long fromN;
    int movedLast;
    int xpos;
};

queue<QData> q;

void q_push(QData d)
{
    if (visited.find(d.num) != visited.end())
        return;
    visited[d.num] = d.movedLast;
    path[d.num] = d.fromN;
    q.push(d);
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    int empts = 0;
    int numed = 0;

    for (int i = 0; i < 9; i++)
    {
        char x;
        cin >> x;
        int n = 0;
        if (x != 'X')
            n = x - '0';
        else
            empts = i;
        numed = numed * 10 + n;
        initalL[i] = n;
    }

    if (numed == 123456780)
    {
        cout << "0";
        return 0;
    }

    q_push({numed,
            -1,
            -1,
            empts});

    int t = 0;
    while (!q.empty())
    {
        unsigned long qs = q.size();
        while (qs--)
        {
            QData qf = q.front();
            q.pop();

            if (qf.num == 123456780)
            {
                cout << t << "\n";
                // [Todo] Make output
                stack<int> s;
                int printingNow = 123456780;
                while (printingNow != numed)
                {
                    s.push(visited[printingNow]);
                    printingNow = path[printingNow];
                }
                while (!s.empty())
                {
                    cout << s.top() << " ";
                    s.pop();
                }
                return 0;
            }

            pii xXY = idxToXY[qf.xpos];

            for (int i = 0; i < 4; i++)
            {
                int swapX = xXY.first + dx[i];
                int swapY = xXY.second + dy[i];

                if (swapX < 0)
                    continue;
                if (swapY < 0)
                    continue;
                if (swapX > 2)
                    continue;
                if (swapY > 2)
                    continue;

                int swaped = swap(qf.num,
                                  xXY.first,
                                  xXY.second,
                                  swapX,
                                  swapY);

                q_push({swaped,
                        qf.num,
                        (int)(qf.num / (long long)divid[8 - swapY * 3 - swapX]) % 10,
                        swapY * 3 + swapX});
            }
        }

        t++;
    }
}