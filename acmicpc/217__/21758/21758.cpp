#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n = 0;
    cin >> n;
    
    vector<int> map;
    vector<int> sum;
    
    map.push_back(0);
    sum.push_back(0);
    
    for(int i = 1;i <= n;i++){
        int num = 0;
        cin >> num;
        map.push_back(num);
        sum.push_back(num + sum[i - 1]);
    }
    
    int ans = 0;
    for(int i=2; i<n; i++){ // 벌벌통
        ans=max(ans, sum[n] - map[1] - map[i] + sum[n] - sum[i]);
    }
    for(int i=2; i<n; i++){ // 통벌벌
        ans=max(ans, sum[n] - map[n] - map[i] + sum[i-1]);
    }
    for(int i=2; i<n; i++){ // 벌통벌
        ans=max(ans, sum[i] - map[1] + sum[n] - sum[i-1] - map[n]);
    }
    
    cout << ans;
}
