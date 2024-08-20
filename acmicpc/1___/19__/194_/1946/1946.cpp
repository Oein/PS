#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int price[100010];

int main(){
    int t = 0;
    cin >> t;
    while(t--){
        int c;
        cin >> c;
        
        int tmp_ = 0;
        while(tmp_ < c){
            int x;
            cin >> x;
            cin >> price[x];
            tmp_++;
        }
        
        int tmp__ = 1;
        int lp = c + 10;
        int ans = 0;
        while(tmp__ <= c){
            if(price[tmp__] < lp){
                ans++;
                lp = price[tmp__];
                
            }
            tmp__++;
        }
        
        cout << ans << "\n";
    }
}