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

    char c;
    cin >> c;
    switch (c)
    {
    case 'M':
        cout << "MatKor";
        break;
    case 'W':
        cout << "WiCys";
        break;
    case 'C':
        cout << "CyKor";
        break;
    case 'A':
        cout << "AlKor";
        break;
    case '$':
        cout << "$clear";
        break;
    default:
        break;
    }
}
