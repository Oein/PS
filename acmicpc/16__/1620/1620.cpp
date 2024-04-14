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
    int cnt, q;
    cin >> cnt >> q;
    map<string, int> msi;
    map<int, string> mis;
    for (int i = 1; i <= cnt; i++)
    {
        string s;
        cin >> s;
        msi[s] = i;
        mis[i] = s;
    }
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9')
        {
            cout << mis[stoi(s)] << '\n';
        }
        else
        {
            cout << msi[s] << '\n';
        }
    }
}
