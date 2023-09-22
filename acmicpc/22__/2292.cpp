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
    
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1;
        return 0;
    }
    n--;
    int nowSubst = 6;
    int nowNeed = 2;
    while (n > nowSubst) {
        n -= nowSubst;
        nowSubst += 6;
        nowNeed++;
    }
    cout << nowNeed;
}
