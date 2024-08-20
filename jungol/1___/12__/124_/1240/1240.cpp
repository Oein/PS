#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<int , int> pii;

ll n , ans = 1;

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;

    ll low = 1 , high = n , mid;
    while(low <= high){
        mid = (low +high) / 2;
        if(n / mid == mid){
            // ans
            break;
        }
        else if(n / mid > mid){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }
    if(n < mid * mid){
        mid--;
    }
    cout << mid;
}
