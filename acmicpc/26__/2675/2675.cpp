#include <bits/stdc++.h>
using namespace std;
int main(){
    int t = 0;
    cin >> t;
    for(int i = 0;i < t;i++){
        int loopTime = 0;
        string str = "";
        cin >> loopTime >> str;
        for(int j=0;j < str.size();j++){
            for(int k = 0;k < loopTime;k++){
                cout << str[j];
            }
        }
        
        cout << "\n";
    }
}
