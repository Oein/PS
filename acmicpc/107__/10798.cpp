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
#include <queue>
#include <numeric>

using namespace std;
using ull = unsigned long long;
using ll = long long;

int main() {
    string a[5];
    unsigned long mlen = 0;
    for(int i =0; i < 5;i++) {
        cin >> a[i];
        mlen = max(a[i].size(), mlen);
    }
    
    for(int i = 0;i < mlen;i++) {
        for(int j = 0;j < 5;j++) {
            if(a[j].size() <= i) continue;
            cout << a[j][i];
        }
    }
}
