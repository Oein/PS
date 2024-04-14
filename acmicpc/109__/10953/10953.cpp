#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;
    int a = 0;
    int b = 0;
    
    cin >> t;
    
    
    char temp_ = ' ';
    for(int i = 0;i < t;i++){
        cin >> a >> temp_ >> b;
        cout << a + b << "\n";
    }
}
