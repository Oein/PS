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
    
    stack<int> s;
    int n;
    cin >> n;
    while (n--) {
        int n;
        cin >> n;
        if(n == 1) {
            int j;
            cin >> j;
            s.push(j);
            continue;
        }
        
        if(n == 2) {
            if(s.empty()) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
            continue;
        }
        
        if(n == 3) {
            cout << s.size() << "\n";
            continue;
        }
        
        if(n == 4) {
            cout << (s.empty() ? 1 : 0) << "\n";
            continue;
        }
        
        cout << (s.empty() ? -1 : s.top()) << "\n";
    }
}
