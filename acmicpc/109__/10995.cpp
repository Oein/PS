#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string output = "";
    int n = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        output += "* ";
    }
    
    for(int i = 0;i < n;i++){
        if(i % 2 == 1) cout << " ";
        cout << output << "\n";
    }
}
