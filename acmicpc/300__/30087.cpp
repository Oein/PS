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
    while (n--)
    {
        string x;
        cin >> x;
        string ans;
        if (x == "Algorithm")
            ans = "204";
        if (x == "DataAnalysis")
            ans = "207";
        if (x == "ArtificialIntelligence")
            ans = "302";
        if (x == "CyberSecurity")
            ans = "B101";
        if (x == "Network")
            ans = "303";
        if (x == "Startup")
            ans = "501";
        if (x == "TestStrategy")
            ans = "105";
        cout << ans << '\n';
    }
}
