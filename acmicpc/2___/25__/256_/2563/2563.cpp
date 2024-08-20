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

bool arr[105][105];

int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        for(int x = a; x < a + 10; x++)
            for(int y = b; y < b + 10; y++)
                arr[y][x] = 1;
    }
    int a = 0;
    for(int x = 1;x <= 100;x++)
        for(int y = 1;y <= 100; y++)
            if(arr[y][x]) a++;
    cout << a;
}
