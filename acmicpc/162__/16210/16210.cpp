#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> xs,ys;
pair<ll,ll> locations[500005];

ll prex[500005];
ll prey[500005];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        ll x,y;
        cin>>x>>y;
        
        locations[i] = {x , y};
        xs.push_back(x);
        ys.push_back(y);
    }
    
    sort(xs.begin() , xs.end());
    sort(ys.begin() , ys.end());
    
    for(int i=0; i < n; i++){
        prex[i+1] = prex[i] + xs[i];
        prey[i+1] = prey[i] + ys[i];
    }
    
    ll ans = 10000000000000000;
    int ans_ind = 0;
    
    for(int i=1; i <= n; i++){
        int a = lower_bound(xs.begin(),xs.end(),locations[i].first)-xs.begin();
        int b = lower_bound(ys.begin(),ys.end(),locations[i].second)-ys.begin();
        
        ll ans_x = prex[n] - (2 * prex[a]) + ((ll)(2 * a - n) * locations[i].first);
        ll ans_y = prey[n] - (2 * prey[b]) + ((ll)(2 * b - n) * locations[i].second);
        
        if(ans > ans_x + ans_y){
            ans = ans_x + ans_y;
            ans_ind = i;
        }
    }
    cout << ans_ind;
    return 0;
}
