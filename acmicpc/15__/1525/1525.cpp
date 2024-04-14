#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;using x=int;
x dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1},i,j,a;
int main()
{
    x w = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> a;
            if (a == 0)
                a = 9;
            w = w * 10 + a;
        }
    }

    map<x, x> d;

    d[w] = 0;

    queue<int> q;
    q.push(w);

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        string r = to_string(t);
        int u = r.find('9');
        int x = u / 3;
        int y = u % 3;

        for (int i = 0; i < 4; i++)
        {
            int p = x + dx[i];
            int z = y + dy[i];
            if (p >= 0 && p < 3 && z >= 0 && z < 3)
            {
                string c = r;
                swap(c[x * 3 + y], c[p * 3 + z]);
                int v = stoi(c);

                if (d.count(v) == 0)
                {
                    d[v] = d[t] + 1;
                    q.push(v);
                }
            }
        }
    }

    if (d.count(123456789) == 0)
        cout << -1;
    else
        cout << d[123456789];
}
