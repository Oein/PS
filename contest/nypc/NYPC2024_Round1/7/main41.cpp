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

int n;
vector<int> a;

void rmain()
{
    int l, r;
    cin >> l >> r;
    l--, r--;

    map<int, int> m;
    for (int i = l; i <= r; i++)
    {
        m[a[i]]++;
    }

    int ans = 0;
    for (auto [k, v] : m)
    {
        if (v == 1)
        {
            ans = k;
            break;
        }
    }
    cout << ans << '\n';
}

vector<vector<int>> v;
int q;

void rmainx()
{
    int l, r;
    cin >> l >> r;
    vector<int> res(30, 0);
    for (int i = 0; i < 30; i++)
    {
        res[i] = v[r][i] - v[l - 1][i];
    }
    int ans = 0;
    for (int i = 0; i < 30; i++)
    {
        if (res[i] == 1)
        {
            ans = i + 1;
            break;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n <= 3000)
    {
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }

        cin >> q;
        while (q--)
        {
            rmain();
        }
    }
    else
    {
        vector<int> initv(30, 0);
        v.push_back(initv);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            x--;
            initv[x]++;
            v.push_back(initv);
        }

        cin >> q;
        while (q--)
        {
            rmainx();
        }
    }
}
