// main.cpp
#include <future>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <chrono>
#include <vector>
#include <sys/resource.h>
#include <sys/time.h>

// solution.cpp
#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <cstring>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <algorithm>

// using
using namespace std;

// typedef
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// direction
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// config defines
#define TIMEOUT 1000LL
#define SOLUTION_FUNCTION main_

// Main
int res[105][105];
int n;
void t1() {
    for(int i = 0; i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }
}
void t2() {
    for(int i = 0; i < n;i++) {
        if(i % 2 == 0)
            for(int j = 1;j <= n;j++) {
                cout << j << " ";
            }
        else
            for(int j = n;j >= 1;j--) {
                cout << j << " ";
            }
        cout << "\n";
    }
}
void t3() {
    for(int i = 1; i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cout << i * j << " ";
        }
        cout << "\n";
    }
}
void main_()
{
    int t;
    cin >> n >> t;
    
    if(t == 1) t1();
    if(t == 2) t2();
    if(t == 3) t3();
}

#ifdef ONLINE_JUDGE
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    main_();
    return 0;
}
#endif
