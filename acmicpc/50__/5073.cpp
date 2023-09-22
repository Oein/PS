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

void it() {
    vector<int> a;
    for(int i = 0;i < 3;i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    if(a[0] == 0 &&  a[1] == 0 && a[2] == 0) exit(0);
    sort(a.begin(), a.end());
    if(a[0] + a[1] <= a[2]) cout << "Invalid\n";
    else if(a[0] == a[2] && a[0] == a[1]) cout << "Equilateral\n";
    else if(a[1] == a[0] || a[1] == a[2]) cout << "Isosceles\n";
    else cout << "Scalene\n";
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(true) it();
}
