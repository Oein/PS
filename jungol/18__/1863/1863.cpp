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

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// union find
// max 50000 people
// max 100000 joins

int n, m;
int unionPars[50005];
bool used[50005];

int union_find(int x)
{
    if (unionPars[x] == x)
        return x;
    return unionPars[x] = union_find(unionPars[x]);
}

void union_join(int a, int b)
{
    int ar = union_find(a);
    int br = union_find(b);

    unionPars[ar] = br;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        unionPars[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        union_join(a, b);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        union_find(i);
        if (used[unionPars[i]])
            continue;

        used[unionPars[i]] = 1;
        ans++;
    }
    cout << ans;
}