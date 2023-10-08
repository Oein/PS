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

    int n; // max : 1,000,000
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // i == 생성자
        int sum = 0;
        int temp = i;
        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum + i == n)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}
