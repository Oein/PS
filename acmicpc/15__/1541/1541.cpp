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
    string str;
    cin >> str;

    int wk = 0;
    int res = 0;
    vector<int> v;
    bool minus = false;
    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] == '-' || str[i] == '+' || i == str.size())
        {
            if (minus)
                res -= wk;
            else
                res += wk;

            wk = 0;
        }
        else
        {
            wk *= 10;
            wk += str[i] - '0';
        }

        if (str[i] == '-')
        {
            minus = true;
        }
    }

    cout << res;
}
