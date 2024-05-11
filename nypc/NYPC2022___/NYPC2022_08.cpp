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
vector<ull> a;
set<vector<ull>> used;

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << "0";
        return 0;
    }

    if (n == 2)
    {
        int neededT = 0;
        while (a[1] != a[0])
        {
            int ga = 1;
            if (neededT % 3 == 1)
            {
                ga = 2;
            }
            if (neededT % 3 == 2)
            {
                ga = 4;
            }

            if (a[0] < a[1])
            {
                a[0] += ga;
            }
            else
            {
                a[1] += ga;
            }

            neededT++;
        }

        cout << neededT << endl;
        return 0;
    }

    cout << "IDK";
}