#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,ans = 0;
    cin >> n;
    vector<int> arr;
    for(int i = 0;i < n;i++) {
        int g;
        cin >> g;
        arr.push_back(g);
    }
    int v;
    cin >> v;
    for(int i = 0;i < n;i++) {
        if(arr[i] == v)ans++;
    }
    cout << ans;
}