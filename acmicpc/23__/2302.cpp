#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int memo[45];
int vip[45];

int main(){
    cin.tie(0); cout.tie(0);
    int n , m;
    cin >> n >> m;
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    
    for(int i = 3; i <= n; i++) memo[i] = memo[i - 1] + memo[i - 2];
    
    int ans = 1;
    int st = 0;
    for(int i = 0;i < m;i++) {
        int g;
        cin >> g;
        ans = ans * memo[g - st - 1];
        st = g;
    }
    
    ans = ans * memo[n - st];
    cout << ans;
}
