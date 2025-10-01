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
    
    int nu;
    cin >> nu;
    int n = 1;
    while (nu > n) {
        nu -= n;
        n++;
    }
    nu--;
    bool isNback = n % 2 == 1;
    int f = (isNback ? 1 : n);
    int s = (isNback ? n : 1);
    
    if(isNback) {
        s -= nu;
        f += nu;
    } else {
        s += nu;
        f -= nu;
    }
    cout << s << "/" << f;
}
