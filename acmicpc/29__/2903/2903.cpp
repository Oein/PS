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

int danwe[] = {25,10,5,1};

int main()
{
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int cnt = 2;
    while (n--) {
        cnt += cnt - 1;
    }
    cout << cnt * cnt;
}
