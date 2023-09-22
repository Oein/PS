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
    int nowGet = 1;
    while (n--) {
        int w;
        cin >> w;
        bool igot = false;
        if(w == nowGet) {
            nowGet++;
            igot = true;
        }
        
        while (!s.empty() && s.top() == nowGet) {
            s.pop();
            nowGet++;
        }
        
        if(!igot && w == nowGet) {
            nowGet++;
            igot = true;
        }
        
        if(!igot) {
            s.push(w);
        }
    }
    
    if(s.size() == 0) cout << "Nice";
    else cout << "Sad";
}
