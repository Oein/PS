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
void main_()
{
    int n;
    cin >> n;
    
    int num = 1;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            res[j][i] = num++;
    
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}

#ifdef ONLINE_JUDGE
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    main_();
    return 0;
}
#endif
