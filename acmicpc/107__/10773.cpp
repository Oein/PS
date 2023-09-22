#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    stack<int> x;
    cin >> k;
    for(int i = 0;i < k;i++) {
        int g;
        cin >> g;
        if(g == 0)x.pop();
        else x.push(g);
    }
    k = 0;
    while(!x.empty()){
        k += x.top();
        x.pop();
    }
    cout << k;
}