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
typedef unsigned long long ull;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n;
int x[155];
int a[155];
int b[155];
bool used[155];

ull max_ = 0;
ull calc_ans = 0;

void dfs(int where)
{
    if (where == n)
    {
        return;
    }
    if (used[where])
        dfs(where + 1);
    for (int i = where + 1; i < n; i++)
    {
        if (used[i])
            continue;
        used[i] = true;
        calc_ans +=
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
}