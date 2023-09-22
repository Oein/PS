#include <bits/stdc++.h>
using namespace std;
int main(){
    int all = 0;
    for(int i = 0;i < 5;i++){
        int in = 0;
        cin >> in;
        if(in < 40){
            in = 40;
        }
        all += in;
    }
    cout << all / 5;
}
