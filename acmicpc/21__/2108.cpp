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

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

struct Pos
{
    int x;
    int y;
};

int used[10005] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;

    double sum = 0;
    int mostUsed = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
        used[x + 4000]++;

        if (used[x + 4000] >= used[mostUsed + 4000])
            mostUsed = x;
    }
    vector<int> mu;
    for (int i = -4000; i <= 4000; i++)
    {
        if (used[i + 4000] == used[mostUsed + 4000])
            mu.push_back(i);
    }
    int rd = round(sum / n);
    if (rd == -0)
        rd = 0;
    cout << rd << "\n";
    sort(v.begin(), v.end());
    cout << v[(n - 1) / 2] << "\n";
    cout << (mu.size() == 1 ? mu[0] : mu[1]) << "\n";
    cout << v[n - 1] - v[0] << "\n";
}
