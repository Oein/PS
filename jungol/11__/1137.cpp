#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <numbers>
#include <cassert>

/**
 3 1 10000000 10000000 10000000
 */

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pii;

const int ml = 505;
ll works[ml];
ll maxW = 0;

int m , k;

bool solve_(ll ma_) {
    if(ma_ < maxW) return 0;
    int cnt = 1;
    ll sum = 0;
    for(int i = 0;i < m;i++) {
        if(sum + (ll)works[i] > ma_) {
            sum = (ll)works[i];
            cnt++;
        }else {
            sum += (ll)works[i];
        }
    }
    
    return cnt <= k;
}

void solve() {
    cin >> m >> k;
    maxW = 0;
    for(int i = 0;i < m;i++) {
        cin >> works[i];
        maxW = max(maxW , works[i]);
    }
    
    ll s = 0 , e = 1 , ableMid = -1;
    // get E;
    while(!solve_(e)) e <<= 1;
    while(s + 1 < e) {
        ll mid = (s + e) / 2;
        if(solve_(mid)) {
            e = mid;
            ableMid = mid;
        }
        else s = mid;
    }
    
    ll sum = 0;
    ll cnt = 1;
    vector<bool> spliter(m);
    for(int i = m - 1;i >= 0;i--) {
        if(sum + (ll)works[i] > ableMid) {
            sum = (ll)works[i];
            cnt++;
            spliter[i] = true;
        }else {
            sum += (ll)works[i];
        }
    }
    
    for(int i = 0;i < m;i++) {
        if(cnt >= k) break;
        if(!spliter[i]) {
            spliter[i] = 1;
            cnt++;
        }
    }
    
    for(int i = 0;i < m;i++) {
        cout << works[i] << " ";
        if(spliter[i]) cout << "/ ";
    }
    cout << "\n";
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll tc = 1;
    cin >> tc;
    while(tc--) solve();
}
