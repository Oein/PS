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

int n;
vector<int> path[300005];

long long d = 0;

void getD() {
    for(int i = 1;i <= n;i++) {
        if(path[i].size() < 2) continue;
        for(int j = 0;j < path[i].size();j++) {
            if(path[i][j] < i) continue;
            if(path[path[i][j]].size() < 2) continue;
            d += ((path[i].size() - 1) * (path[path[i][j]].size() - 1));
        }
    }
}

long long g = 0;

void getG() {
    for(int i = 1; i <= n;i++) {
        long long cnt = path[i].size();
        if(cnt >= 3)
            g += (cnt * (cnt - 1) * (cnt - 2)) / 6;
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    
    getD();
    getG();
    
    if(d > g * 3) cout << "D";
    else if(d == g * 3) cout << "DUDUDUNGA";
    else cout << "G";
}
