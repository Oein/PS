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

int to[20005];
bool vis[20005];
ll ans = 1;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> to[i];
    for(int i = 1; i <= n;i++) {
        if(vis[i]) continue;
        ll cnt = 0;
        for(int j = i;!vis[j];j = to[j]) {
            vis[j] = 1;
            cnt++;
        }
        ans *= cnt / gcd(ans, cnt);
    }
    cout << ans;
}
    
