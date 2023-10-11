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
    int s = 0;
    while (n--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "add")
        {
            int x;
            cin >> x;
            s = s | (1 << x);
        }
        if (cmd == "remove")
        {
            int x;
            cin >> x;
            s = s & (((1 << 21) - 1) - (1 << x));
        }
        if (cmd == "check")
        {
            int x;
            cin >> x;
            if (s & (1 << x))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        if (cmd == "toggle")
        {
            int x;
            cin >> x;
            s = s ^ (1 << x);
        }
        if (cmd == "all")
        {
            s = (1 << 21) - 1;
        }
        if (cmd == "empty")
        {
            s = 0;
        }
    }
}
