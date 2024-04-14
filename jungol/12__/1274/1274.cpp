#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , dou = 1 , ans = 0;
    cin >> n;
    string s = to_string(n);
    
    for(int i = s.size() - 1;i >= 0;i--){
        ans += dou * (s[i] - '0');
        dou *= 2;
    }

    if(s.size() == 8){
        ans -= dou / 2 * (s[0] - '0');
        if(s[0] == '1'){
            ans = ans - 128;
        }
    }

    cout << ans;
}