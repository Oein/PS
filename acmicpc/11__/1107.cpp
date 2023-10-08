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
    int n, m;
    cin >> n >> m;
    vector<bool> broken(10, false);
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        broken[temp] = true;
    }

    int ans = INT_MAX;
    const int NOW_WATCHING = 100;

    if (m == 10)
    {
        cout << abs(NOW_WATCHING - n);
        return 0;
    }

    // 0 처리
    if (!broken[0])
        ans = min(ans, n + 1);

    for (int i = 1; i <= 1000000; i++)
    {
        bool able = true;
        int temp = i;
        while (temp)
        {
            if (broken[temp % 10])
            {
                able = false;
                break;
            }
            temp /= 10;
        }
        if (able)
        {
            int press = 0;
            temp = i;
            while (temp)
            {
                press++;
                temp /= 10;
            }
            // 현재 채널이 i임
            press += abs(i - n); // i에서 n으로 이동
            ans = min(ans, press);
        }
    }
    cout << min(ans, abs(NOW_WATCHING - n));
}
