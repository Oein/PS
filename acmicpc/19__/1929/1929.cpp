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

bool isPrimeNum[1000005] = {
    0,
};

void calcisPrime()
{
    memset(isPrimeNum, 1, sizeof(isPrimeNum));
    isPrimeNum[0] = false;
    isPrimeNum[1] = false;

    for (int i = 2; i <= 1000000; i++)
    {
        if (!isPrimeNum[i])
            continue;
        for (int j = i * 2; j <= 1000000; j += i)
        {
            isPrimeNum[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calcisPrime();
    int f, t;
    cin >> f >> t;
    for (int i = f; i <= t; i++)
    {
        if (isPrimeNum[i])
            cout << i << '\n';
    }
}
