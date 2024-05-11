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
typedef unsigned long ull;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int buildings[200002];
bool used[1000002];
int n;

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int maxShown = 0;
    int nowShowing = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> buildings[i];
    }

    int left = 0;
    int right = 0;
    while (right < n && left < n)
    {
        if (used[buildings[right]] == false)
        {
            used[buildings[right]] = 1;
            right++;
            nowShowing++;
            // cout << "NEW";
        }
        else
        {
            used[buildings[left]] = 0;
            left++;
            nowShowing--;
            //  cout << "REMOVE";
        }

        // cout << " " << left << " ~ " << right << "\n";

        maxShown = max(maxShown, nowShowing);
    }

    cout << maxShown;
}