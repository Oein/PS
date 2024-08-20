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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Pos
{
    int x;
    int y;
};

long long t[100005];
long long d[100005];
vector<pii> stick;
vector<int> tvec, dvec;

int n, l;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        pii s;
        cin >> s.first >> s.second;
        stick.push_back(s);
        tvec.push_back(s.first);
        dvec.push_back(s.second);
    }

    sort(stick.begin(), stick.end());
    sort(tvec.begin(), tvec.end());
    sort(dvec.begin(), dvec.end());

    tvec.erase(unique(tvec.begin(), tvec.end()), tvec.end());
    dvec.erase(unique(dvec.begin(), dvec.end()), dvec.end());

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int ti = lower_bound(tvec.begin(), tvec.end(), stick[i].first) - tvec.begin();
        int di = lower_bound(dvec.begin(), dvec.end(), stick[i].second) - dvec.begin();

        int len = l + abs(stick[i].first - stick[i].second);
        long long t_ = t[ti], d_ = d[di];

        t[ti] = max(t_, d_ + len);
        d[di] = max(d_, t_ + len);

        ans = max(ans, max(t[ti], d[di]));
    }

    cout << ans;
}
