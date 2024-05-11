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

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    bool al60 = true;
    int sum = 0;
    vector<int> angles;
    for(int i = 0;i < 3;i++) {
        int deg;
        cin >> deg;
        sum += deg;
        angles.push_back(deg);
        if(deg!=60)al60=false;
    }
    if(sum != 180) {
        cout << "Error";
        return 0;
    }
    if(al60) {
        cout << "Equilateral";
        return 0;
    }
    sort(angles.begin(), angles.end());
    if(angles[0] == angles[1] || angles[1] == angles[2]) {
        cout << "Isosceles";
        return 0;
    }
    cout << "Scalene";
    return 0;
}
