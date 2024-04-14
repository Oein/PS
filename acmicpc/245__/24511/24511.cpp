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

bool isSt[100005];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    deque<int> q;
    for(int i = 0; i< n;i++) {
        int a;
        cin >> a;
        if(a == 1) isSt[i] = 1;
    }
    for(int i = 0;i < n;i++) {
        int dt;
        cin >> dt;
        if(isSt[i]) continue;
        q.push_front(dt);
    }
    int m;
    cin >> m;
    while (m--) {
        int dt;
        cin >> dt;
        q.push_back(dt);
        cout << q.front() << ' ';
        q.pop_front();
    }
}
