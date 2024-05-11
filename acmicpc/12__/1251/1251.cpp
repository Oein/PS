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

    string s;
    cin >> s;
    string ans = "";
    while (ans.size() < s.size())
        ans += 'z';
    for (int lst = 0; lst < s.size(); lst++)
        for (int mst = lst + 1; mst < s.size(); mst++)
            for (int rst = mst + 1; rst < s.size(); rst++)
            {
                string l = s.substr(0, mst);
                string m = s.substr(mst, rst - mst);
                string r = s.substr(rst);
                reverse(l.begin(), l.end());
                reverse(m.begin(), m.end());
                reverse(r.begin(), r.end());

                string tmp = l + m + r;
                if (ans > tmp)
                    ans = tmp;
            }
    cout << ans;
}
