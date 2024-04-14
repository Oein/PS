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
    int n, m;
    cin >> n >> m;
    set<string> s;
    while (n--)
    {
        string t;
        cin >> t;
        s.insert(t);
    }
    vector<string> v;
    while (m--)
    {
        string t;
        cin >> t;
        if (s.find(t) != s.end())
            v.push_back(t);
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto i : v)
    {
        cout << i << '\n';
    }
}
