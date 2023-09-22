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

int n, m;
int arr[105][105];

int main()
{
    cin.tie(0);
    cout.tie(0);
    int m = 0;
    int q = 0, w = 0;
    for(int i = 0;i < 9;i++)
        for(int j = 0;j < 9;j++) {
            int x;
            cin >> x;
            if(x > m) {
                q = i;
                w = j;
                m = x;
            }
        }
    cout << m << "\n" << q + 1 << " " << w + 1;
}
