#include <bits/stdc++.h>
using namespace std;
int main(){
    string a = "";
    string b = "";
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int aInt = atoi(a.c_str());
    int bInt = atoi(b.c_str());
    
    if(aInt < bInt){
        cout << bInt;
    }else{
        cout << aInt;
    }
}
