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
    int t;
    string s;
    cin >> n >> t >> s;

    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int k = 0;
        if (s[i] == 'O')
            continue;

        while (s[i + 1] == 'O' && s[i + 2] == 'I')
        {
            k++;
            if (k == n)
            {
                k--;
                ans++;
            }
            i += 2;
        }
    }

    cout << ans;
}
