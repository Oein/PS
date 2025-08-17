#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

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

int n;
vector<int> v;

int calc(int st)
{
    int ans = 0;
    // 0부터 시작
    int lastUpValue = v[st];
    int lastDownValue = v[st + 1];
    int cnt = 0;
    for (int i = st; i < n; i++)
    {
        const bool isUp = i % 2 == st;
        const int now = v[i];
        const bool able = isUp ? lastUpValue <= now : lastDownValue >= now;

        // printf("%2d | ", i);
        // printf("%s | ", isUp ? "UP" : "DN");
        // printf("last %2d | ", isUp ? lastUpValue : lastDownValue);
        // printf("now %2d | ", now);
        // printf("able %c | ", able ? 'T' : 'F');

        if (isUp)
        {
            if (able)
            {
                cnt++;
            }
            else
            {
                cnt = 2;
                lastDownValue = v[i - 1];
            }
            lastUpValue = now;
        }
        else
        {
            // cal down
            if (able)
            {
                cnt++;
            }
            else
            {
                cnt = 2;
                lastUpValue = v[i - 1];
            }
            lastDownValue = now;
        }

        // printf("CN %2d", cnt);

        // printf("\n");

        ans = max(ans, cnt);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 1 || n == 2)
    {
        printf("%d", n);
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int ans = 0;
    // printf("=============== ST0 ==============\n");
    ans = calc(0);

    // printf("\n=============== ST1 ==============\n");
    ans = max(ans, calc(1));

    // printf("ANS %2d", ans);
    printf("%d", ans);
}
