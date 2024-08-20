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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    vector<priority_queue<int, vector<int>, greater<int>>> vpq(n + 1); // vpq[num]: idx pq
    set<pair<int, int>> cset;                                          // count, num
    set<pair<int, int>> iset;                                          // idx, num

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        vpq[v[i]].push(i + 1);
        if (vpq[v[i]].size() > ceil(n / 2.0))
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vpq[i].empty())
        {
            cset.insert({vpq[i].size(), i});
            iset.insert({vpq[i].top(), i});
        }
    }

    int last = -1;
    int curn = n;
    while (curn--)
    {

        auto cnt_item = cset.rbegin();

        if (cnt_item->first > ceil(curn / 2.0))
        {
            // use maxelem
            auto [cnt, num] = *cnt_item;
            int idx = vpq[num].top();

            last = num;
            cout << vpq[num].top() << ' ';

            vpq[num].pop();
            iset.erase({idx, num});
            cset.erase({cnt, num});

            if (cnt - 1)
            {
                cset.insert({cnt - 1, num});
                iset.insert({vpq[num].top(), num});
            }

            continue;
        }

        // use minidx
        auto idx_item = iset.begin();
        while (idx_item->second == last && idx_item != iset.end())
            idx_item++;

        auto [idx, num] = *idx_item;
        int cnt = vpq[num].size();

        last = num;
        cout << idx << ' ';

        vpq[num].pop();
        iset.erase({idx, num});
        cset.erase({cnt, num});

        if (cnt - 1)
        {
            cset.insert({cnt - 1, num});
            iset.insert({vpq[num].top(), num});
        }
    }
}
