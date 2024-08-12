#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool board[5][5];

struct Data
{
    bool board[5][5];
    int x;
};

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    bool allO = true;
    bool allX = true;

    if (n > 5 || m > 5)
    {
        cout << "-1";
        return 0;
    }

    int xCount = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            if (x == 'X')
            {
                board[i][j] = true;
                allO = false;
                xCount++;
            }
            else
                allX = false;
        }
    }

    if (allO)
    {
        cout << "0";
        return 0;
    }

    if (allX)
    {
        cout << "5";
        return 0;
    }

    if (xCount == 1)
    {
        cout << "1";
        return 0;
    }

    queue<Data> q;
    Data x;
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            x.board[j][j] = board[j][k];
        }
    }

    for (int i = 0; i < m; i++)
    {
        x.x = i;
        q.push(x);
    }

    int t = 0;
    int y = 0;
    while (!q.empty())
    {
        unsigned long qs = q.size();
        cout << "LOOP " << qs << " t : " << t << "\n";

        if (t > 8)
        {
            return 0;
        }

        while (qs--)
        {
            Data qf = q.front();
            q.pop();

            if (y == n)
            {
                bool asd = true;
                for (int i = 0; i < n && asd; i++)
                {
                    for (int j = 0; j < m && asd; j++)
                    {
                        asd = asd && !board[i][j];
                    }
                }

                if (asd)
                {
                    cout << t;
                    return 0;
                }
                continue;
            }

            if (qf.x > 0)
            {
                qf.x--;
                bool al = qf.board[y + 1][qf.x];
                qf.board[y + 1][qf.x] = 0;
                q.push(qf);
                qf.board[y + 1][qf.x] = al;
                qf.x++;
            }

            bool al = qf.board[y + 1][qf.x];
            qf.board[y + 1][qf.x] = 0;
            q.push(qf);
            qf.board[y + 1][qf.x] = al;

            if (qf.x < 3)
            {
                qf.x++;
                bool al = qf.board[y + 1][qf.x];
                qf.board[y + 1][qf.x] = 0;
                q.push(qf);
                qf.board[y + 1][qf.x] = al;
                qf.x--;
            }
        }

        t++;
        y++;
        y %= n;
    }
}