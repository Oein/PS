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
#include <iomanip>

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

double factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

double calc(int n)
{
    double ans = 1;
    if (n == 0)
        return 1;
    for (int i = 1; i <= n; i++)
        ans += double(1 / factorial(i));
    return ans;
}

int main()
{
    printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
    for (int i = 3; i <= 9; i++)
    {
        printf("%d %.9f\n", i, calc(i));
    }
}