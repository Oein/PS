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

int dp[300010];
int picture_last[300010];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;

    vector<pair<int, int>> pictures;
    // pair < height , price >

    pictures.push_back({0, 0});

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        pictures.push_back({a, b});
    }

    sort(pictures.begin(), pictures.end(), cmp);

    int li = 1;
    for (int i = 2; i <= n; i++)
    {
        while (pictures[i].first - pictures[li].first >= s)
            li++;

        picture_last[i] = li - 1;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[picture_last[i]] + pictures[i].second);
        //최대값 = max(나 없음 , 나 있고 앞에 없음)
    }

    cout << dp[n];
}