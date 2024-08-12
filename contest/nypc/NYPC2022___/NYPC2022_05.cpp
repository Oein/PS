#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<int> arr;
int n;

int reverseSt = 0;
int reverseEd = 0;
int lastReverstSt = 0;

ll dynamic_programming()
{
    ll max_so_far = arr[1];

    if (reverseSt == 1)
        max_so_far = arr[reverseEd];

    ll curr_max = max_so_far;

    if (reverseSt == lastReverstSt && reverseSt >= 2)
    {
        lastReverstSt = reverseSt;
        for (int j = reverseSt; j <= n; j++)
        {
            int i = j;
            if (reverseSt <= j && j <= reverseEd)
            {
                // (8 - 1) - (5-1)
                i = reverseEd - (j - reverseSt);
            }
            curr_max = max((ll)arr[i], curr_max + (ll)arr[i]);
            max_so_far = max(max_so_far, curr_max);
        }
    }
    else
    {
        for (int j = 2; j <= n; j++)
        {
            int i = j;
            if (reverseSt <= j && j <= reverseEd)
            {
                // (8 - 1) - (5-1)
                i = reverseEd - (j - reverseSt);
            }
            curr_max = max((ll)arr[i], curr_max + (ll)arr[i]);
            max_so_far = max(max_so_far, curr_max);
        }
    }

    return max_so_far;
}

ll getMaxSum()
{
    return dynamic_programming();
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    arr.resize(n + 1);
    ll ans = LLONG_MIN;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ans = max(ans, (ll)arr[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        reverseSt = i;
        for (int j = i; j <= n; j++)
        {
            if (i != j)
            {
                reverseEd = j;
                // reverse(arr.begin() + i, arr.begin() + j);
                ans = max(ans, getMaxSum());
                // reverse(arr.begin() + i, arr.begin() + j);
            }
        }
    }
    cout << ans;
}