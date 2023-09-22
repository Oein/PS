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
using ll = long long;

const int MAX = 4000000;

bool isNotSosu[MAX + 5] = {1,1,};
vector<int> sosus;

void setupSosu() {
    for(int i = 2; i <= MAX; i++) {
        if(isNotSosu[i]) continue;
        for(int j = i + i; j <= MAX; j += i) {
            isNotSosu[j] = 1;
        }
        sosus.push_back(i);
    }
}

int main() {
    setupSosu();
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    int ans = 0;
    int l = 0;
    int sum = 0;
    for(int r = 0;r < sosus.size() && sosus[r] <= n;r++) {
        sum += sosus[r];
        while(sum > n) {
            sum -= sosus[l];
            l++;
        }
        
        // cout << sosus[r] << " : " << sum << "\n";
        
        if(sum == n) ans++;
    }
    
    cout << ans;
}
