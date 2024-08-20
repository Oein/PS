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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<string> s;
    while (n--)
    {
        string n;
        string t;
        cin >> n >> t;
        if (t[0] == 'e')
            s.insert(n);
        else
            s.erase(n);
    }
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        cout << *it << '\n';
    }
}
