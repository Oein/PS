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
    int a, b;
    cin >> a >> b;
    set<int> a1;
    set<int> a2;
    set<int> b1;
    set<int> b2;
    while (a--)
    {
        int x;
        cin >> x;
        a1.insert(x);
        a2.insert(x);
    }
    while (b--)
    {
        int x;
        cin >> x;
        b1.insert(x);
        b2.insert(x);
    }
    for (auto x : b1)
        if (a1.find(x) != a1.end())
            a1.erase(x);
    for (auto x : a2)
        if (b2.find(x) != b2.end())
            b2.erase(x);

    cout << a1.size() + b2.size();
}
