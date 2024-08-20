#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e = 0, i, q, w = 1000000, u, g[1000005];
vector<int> f;
main()
{
    cin >> a >> b >> c >> d;
    for (i = 0; i < d; i++)
    {
        int o, p;
        cin >> o >> p;
        e = max(e, o);
        if (!g[p])
        {
            f.push_back(p);
            g[p] = 1;
        }
    }

    sort(f.begin(), f.end());
    q = e;
    while (q <= w)
    {
        int z = (q + w) / 2;

        int m = 0;
        int n = -1;
        for (int o : f)
        {
            if (m > c)
                q = z + 1;
            if (o <= n)
                continue;

            n = o + z - 1;
            m++;
        }

        if (m > c)
        {
            q = z + 1;
            continue;
        }

        w = z - 1;
        u = z;
    }
    cout << u;
}
