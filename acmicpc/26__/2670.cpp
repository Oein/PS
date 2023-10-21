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

int n;
vector<double> v;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        double x;
        scanf("%lf", &x);
        v.push_back(x);
    }

    double max = v[0];
    for (int i = 0; i < n; i++)
    {
        double multi = v[i];
        max = max > multi ? max : multi;
        for (int j = i + 1; j < n; j++)
        {
            multi *= v[j];
            if (multi > max)
                max = multi;
        }
    }

    printf("%.3f", max);
}
