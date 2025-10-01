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
    
    deque<int> d;
    int n;
    cin >> n;
    while (n--) {
        int c;
        cin >> c;
        if(c == 1) {
            int j;
            cin >> j;
            d.push_front(j);
            continue;
        }
        if(c == 2) {
            int j;
            cin >> j;
            d.push_back(j);
            continue;
        }
        if(c == 3) {
            if(d.empty()) cout << -1 << "\n";
            else {
                cout << d.front() << "\n";
                d.pop_front();
            }
            continue;
        }
        if(c == 4) {
            if(d.empty()) cout << -1 << "\n";
            else {
                cout << d.back() << "\n";
                d.pop_back();
            }
            continue;
        }
        if(c == 5) {
            cout << d.size() << "\n";
            continue;
        }
        if(c == 6) {
            cout << (d.empty() ? 1 : 0) << "\n";
            continue;
        }
        if(c == 7) {
            cout << (d.empty() ? -1 : d.front()) << "\n";
            continue;
        }
        cout << (d.empty() ? -1 : d.back()) << "\n";
    }
}
