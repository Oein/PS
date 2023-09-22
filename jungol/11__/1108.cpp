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

int n, maxPageIDX = -1;
int d[502][502];

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int f, t;
        cin >> f >> t;
        d[f][t] = 1;
        maxPageIDX = max(maxPageIDX, f);
        maxPageIDX = max(maxPageIDX, t);
    }

    for (int i = 0; i <= maxPageIDX; i++)
    {
        for (int j = 0; j <= maxPageIDX; j++)
        {
            if (!d[i][j])
                d[i][j] = 1000;
        }
    }

    for (int w = 1; w <= maxPageIDX; w++)
    {
        for (int t = 1; t <= maxPageIDX; t++)
        {
            for (int f = 1; f <= maxPageIDX; f++)
            {
                if (w == t || t == f || f == w)
                    continue;
                d[f][t] = min(d[f][t], d[f][w] + d[w][t]);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= maxPageIDX; i++)
    {
        for (int j = 1; j <= maxPageIDX; j++)
        {
            if (i == j)
                continue;
            res += d[i][j];
        }
    }

    printf("%.3f", (double)res / (maxPageIDX * (maxPageIDX - 1)));
}