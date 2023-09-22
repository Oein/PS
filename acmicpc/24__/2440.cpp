#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    for(int i = n;i > 0;i--){
        for(int j = 0;j < i;j++){
            cout << "*";
        }
        cout << "\n";
    }
}
