#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int , int> pi_i;

int n;
int wei[1005];

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++) cin >> wei[i];
    sort(wei,wei+n);
    if(wei[0] != 1) {
        cout << 1;
        return 0;
    }
    int ans = wei[0];
    for(int i = 1;i < n && ans + 1 >= wei[i];i++){
        ans += wei[i];
    }

    cout << ans + 1;
}