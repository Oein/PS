#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int n , q;
const int MAXN = 500000;
int a[MAXN +5];

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    cin >> q;
    for(int i = 0;i < q;i++){
        int fv;
        cin >> fv;
        int low = 0 , high = n - 1;
        bool printed = false;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mid < 0 || mid >= n){
                cout << "-1 ";
                printed = true;
                break;
            }
            if(a[mid] == fv){
                cout << mid << " ";
                printed = true;
                break;
            }
            if(a[mid] < fv){
                low = mid + 1;
            }
            if(a[mid] > fv){
                high = mid - 1;
            }
        }
        if(!printed) cout << "-1 ";
    }
}
