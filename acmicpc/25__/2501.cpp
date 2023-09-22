#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> list;
    int n = 0;
    int k = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        if(n%i == 0){
            list.push_back(n/i);
        }
    }
    
    sort(list.begin() , list.end());
    
    if(list.size() < k){
        cout << "0";
    }else{
        cout << list[k - 1];
    }
}
