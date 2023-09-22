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
    
    vector<int> xl, yl;
    
    for(int i = 0;i < 3;i++) {
        int x, y;
        cin >> x >> y;
        xl.push_back(x);
        yl.push_back(y);
    }
    
    sort(xl.begin(), xl.end());
    sort(yl.begin(), yl.end());
    
    if(xl[0] == xl[1]) cout << xl[2];
    else cout << xl[0];
    cout << " ";
    
    if(yl[0] == yl[1]) cout << yl[2];
    else cout << yl[0];
    cout << " ";
}
