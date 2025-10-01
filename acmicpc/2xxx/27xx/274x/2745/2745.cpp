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

int todec(char x) {
    if(x >= '0' && x <= '9') return x - '0';
    return x - 'A' + 10;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    int num = 0;
    string x;
    int jin;
    cin >> x >> jin;
    int multi = 1;
    for(int i = x.size() - 1; i >= 0;i--) {
        num += todec(x[i]) * multi;
        multi *= jin;
    }
    cout << num;
}
