#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

vector<ll> lans;

int c = 0;
int need = 0;

bool is_posobble(ll mid){
    int cnt = 0;
    for(int i = 0;i < c;i++){
        if(lans[i] >= mid){
            cnt += lans[i] / mid;
        }
    }
    
    if(cnt >= need) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> c >> need;
    
    ll high = 0;
    
    for(int i = 0;i < c;i++){
        ll len = 0;
        cin >> len;
        if(len > high) high = len;
        lans.push_back(len);
    }
    
    ll out_ = 0;
    ll low = 1;
    
    while(low <= high){
        ll mid = (low + high) / 2;
        
        if(is_posobble(mid)){
            if(out_ < mid) out_ = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    
    cout << out_;
}
