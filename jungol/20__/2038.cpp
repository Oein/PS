#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi_i;
typedef pair<pair<int, int>, pair<int, int>> ppi_i__pi_i;
typedef pair<long long, long long> pll_ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int, int> mii;
typedef map<string, int> ms_i;
typedef map<string, string> ms_s;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

#define MAXN 10005
vector<pi_i> points;
int n, dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    points.push_back({0, 0});
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }

    sort(points.begin() + 1, points.end());

    for (int i = 1; i <= n; i++)
    {
        int maxHeight = 0;
        dp[i] = 1234567890;
        for (int j = i; j >= 1; j--)
        {
            maxHeight = max(maxHeight, abs(points[j].second));
            dp[i] = min(dp[i], dp[j - 1] + max(2 * maxHeight, points[i].first - points[j].first));
            //          현재  ,  전거    +                   추가
        }
    }

    cout << dp[n];
}