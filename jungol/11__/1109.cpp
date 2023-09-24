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
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    int ans = 0;
    for(int a = 1; a <= n; a++) {
        for(int b = a; b + a <= n; b++) {
            int c = n - a - b;
            if(c < 1) break;
            if(c < a || c < b) continue;
            if(a + b <= c) continue;
            ans++;
        }
    }
    cout << ans;
}
