#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include <limits>
#include <string>
#include <cmath>
#include <stack>
#include <climits>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int fibo[1007];
    int MOD = 10007;
    
    fibo[1] = 1;
    fibo[2] = 2;
    for(int i = 3; i <= n;i++) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
    cout << (fibo[n] % MOD);
}

// 1 : 1
// 2 : 2
// 3 : 3
// 4 : 5
// 5 : 8
