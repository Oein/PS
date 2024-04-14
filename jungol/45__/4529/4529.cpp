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

int seg[2000005] = {
    0,
};

int n;

void update(int updateAt, int updateTo, int node = 1, int start = 1, int end = n)
{
    if (start == end)
    {
        seg[node] = updateTo;
        // cout << " UPDATE seg[" << node << "(as idx " << updateAt << ")] = " << updateTo << endl;
        return;
    }

    int mid = (start + end) / 2;
    if (updateAt <= mid)
    {
        update(updateAt, updateTo, node * 2, start, mid);
    }
    else
    {
        update(updateAt, updateTo, node * 2 + 1, mid + 1, end);
    }

    // cout << " UPDATE seg[" << node << "(" << start << " ~ " << end << ")] = " << max(seg[node * 2], seg[node * 2 + 1]) << endl;
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}

int query(int from, int to, int node = 1, int start = 1, int end = n)
{
    if (from > end || to < start)
    {
        return 0;
    }

    if (from <= start && end <= to)
    {
        return seg[node];
    }

    int mid = (start + end) / 2;
    return max(query(from, to, node * 2, start, mid), query(from, to, node * 2 + 1, mid + 1, end));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<pair<int, int>> arrinp;
    vector<pair<int, int>> arr;
    arrinp.push_back({-1, -1});
    arr.push_back({-1, -1});
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        arrinp.push_back({x, i});
        // cout << "APPEND " << arr[arr.size() - 1].first << " " << arr[arr.size() - 1].second << endl;
    }
    sort(arrinp.begin() + 1, arrinp.end());
    int minus = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << arr[i].first << " to " << i << endl;
        if (i > 1 && arrinp[i].first == arrinp[i - 1].first)
        {
            minus++;
        }
        arr.push_back({i - minus, arrinp[i].second});
    }
    sort(arr.begin() + 1, arr.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    // for (auto a : arr)
    //     cout << a.first << " ";
    // cout << endl
    //      << endl;

    // update(arr[0].first, 1); // 처음에는 0만 있음
    for (int i = 1; i <= n; i++)
    {
        int maxVal = query(1, arr[i].first - 1);
        // cout << "I " << i << " / "
        //      << "QUERY(" << arr[i].first - 1 << ") > " << maxVal << endl;
        update(arr[i].first, maxVal + 1);

        // cout << endl;
    }

    // for (int i = 1; i <= n; i++)
    //     cout << i << " / " << query(i, i) << "\n";

    cout << query(1, n);
}
