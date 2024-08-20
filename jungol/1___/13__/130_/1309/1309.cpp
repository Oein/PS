#include <bits/stdc++.h>
using namespace std;
long long n;
long long factory(long long num){
    if(num == 0) return 1ll;
    if(num == 1) {
        cout << "1! = 1\n";
        return 1ll;
    }
    cout << num <<"! = " << num <<" * " << num - 1 <<"!\n";
    return num * factory(num - 1);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    cout <<factory(n) <<"\n";
    return 0;
}
