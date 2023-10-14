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

    string s;
    cin >> s;
    if (s[0] == 'A')
    {
        if (s[1] == '+')
            cout << "4.3";
        else if (s[1] == '0')
            cout << "4.0";
        else
            cout << "3.7";
    }
    if (s[0] == 'B')
    {
        if (s[1] == '+')
            cout << "3.3";
        else if (s[1] == '0')
            cout << "3.0";
        else
            cout << "2.7";
    }
    if (s[0] == 'C')
    {
        if (s[1] == '+')
            cout << "2.3";
        else if (s[1] == '0')
            cout << "2.0";
        else
            cout << "1.7";
    }
    if (s[0] == 'D')
    {
        if (s[1] == '+')
            cout << "1.3";
        else if (s[1] == '0')
            cout << "1.0";
        else
            cout << "0.7";
    }
    if (s[0] == 'F')
        cout << "0.0";
}
