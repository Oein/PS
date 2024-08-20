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

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int main()
{
    cin.tie(0);
    cout.tie(0);
    int x, y;
    while (true) {
        cin >> x >> y;
        if(x == 0 && y == 0) break;
        
        if(x < y && y % x == 0) cout << "factor\n";
        else if(x > y && x % y == 0) cout << "multiple\n";
        else cout << "neither\n";
    }
}
