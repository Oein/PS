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

pair<int, int> snail(int s, ull fv)
{
    int size = s, direction = 1;
    int x = -1, y = 0;
    ull n = 0;
    for (; size > 0;)
    {
        // printf("x : %d, y : %d, direction : %d\n", x, y, direction);
        if (n <= fv && n + size * 2 - 1 >= fv)
        {
            if (fv - n <= size)
            {
                x += (fv - n) * direction;
                return {x + 1, y + 1};
            }
            else
            {
                x += size * direction;
                n += size;
                y += (fv - n) * direction;
                return {x + 1, y + 1};
            }

            return {0, 0};
        }

        x += direction * size;
        y += direction * (size - 1);
        n += size * 2 - 1;

        size -= 1;
        direction = -direction;
    }

    return {0, 0};
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ull n, a, b;
        cin >> n >> a >> b;
        // cout << "sa---\n";
        pii sa = snail(n, a);
        // cout << "sb---\n";
        pii sb = snail(n, b);
        // printf("(%d, %d) ~ (%d , %d) / ", sa.first, sa.second, sb.first, sb.second);
        int xd = abs(sa.first - sb.first);
        int yd = abs(sa.second - sb.second);
        if (xd != yd)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}