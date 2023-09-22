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

deque<pair<int , int>> d;

void neg() {
    d.push_front(d.back());
    d.pop_back();
}
void pos() {
    d.push_back(d.front());
    d.pop_front();
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        d.push_back({i, x});
    }
    
    while (!d.empty()) {
        int n = d.front().second;
        cout << d.front().first << " ";
        d.pop_front();
        if(n < 0) neg();
        if(n < 0) {
            n = -n - 1;
            while (n--) {
                neg();
            }
        } else {
            n -= 1;
            while (n--) {
                pos();
            }
        }
    }
}
