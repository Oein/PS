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
#include <climits>

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

const int MAXN = 500000;
vector<pair<int, int> > arr; // pair<실력, idx>
int tree[MAXN] = {
    0,
};

int sum(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, int num)
{
    while (i <= n)
    {
        tree[i] += num;
        i += (i & -i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back({x, i});
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        arr[i].first = i + 1;
        swap(arr[i].first, arr[i].second);
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 - sum(arr[i].second - 1) << '\n';
        update(arr[i].second, 1);
    }
}
