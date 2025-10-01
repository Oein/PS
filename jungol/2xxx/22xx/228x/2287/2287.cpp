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

struct PYummy
{
    long long price;
    long long yummy;
};

long long n, m;

vector<PYummy> cows;
vector<PYummy> shops;

struct Pos
{
    int x;
    int y;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        PYummy a;
        cin >> a.price >> a.yummy;
        cows.push_back(a);
    }

    for (int i = 0; i < m; i++)
    {
        PYummy a;
        cin >> a.price >> a.yummy;
        shops.push_back(a);
    }

    sort(cows.begin(), cows.end(), [](const PYummy a, const PYummy b)
         { return a.yummy < b.yummy; });

    sort(shops.begin(), shops.end(), [](const PYummy a, const PYummy b)
         { return a.yummy < b.yummy; });

    long long ans = 0;
    int j = m - 1;
    multiset<long long> prices;
    for (int i = n - 1; i >= 0; i--)
    {
        for (; j >= 0; j--)
        {
            if (cows[i].yummy <= shops[j].yummy)
            {
                // Able
                prices.insert(shops[j].price);
            }
            else
                break;
        }

        auto lower = prices.lower_bound(cows[i].price);
        if (lower == prices.end())
        {
            cout << -1;
            return 0;
        }

        ans += *lower;
        prices.erase(lower);
    }

    cout << ans;
}
