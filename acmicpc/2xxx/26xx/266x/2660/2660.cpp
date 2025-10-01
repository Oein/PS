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

int n;
int r[51];
int d[51][51];

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            d[i][j] = 123456789;
        }
    }

    while (1)
    {
        int f, t;
        cin >> f >> t;

        if (f == -1 || t == -1)
            break;

        d[f][t] = 1;
        d[t][f] = 1;
    }

    for (int w = 1; w <= n; w++)
    {
        for (int t = 1; t <= n; t++)
        {
            for (int f = 1; f <= n; f++)
            {
                if (w == t || t == f || f == w)
                    continue;
                d[f][t] = min(d[f][t], d[f][w] + d[w][t]);
            }
        }
    }

    int mined = 10000;

    for (int i = 1; i <= n; i++)
    {
        r[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            r[i] = max(r[i], d[i][j]);
        }

        mined = min(mined, r[i]);
    }

    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        if (r[i] == mined)
        {
            a.push_back(i);
        }
    }

    cout << mined << " " << a.size() << "\n";
    for (auto x : a)
        cout << x << " ";
}