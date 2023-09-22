#include <bits/stdc++.h>
using namespace std;
int main() {
    string x;
    getline(cin, x);
    int ans = x.size();
    for(int i = 0;i < x.size();i++) {
        if(x[i] == ':') ans++;
        if(x[i] == '_') ans += 5;
    }
    cout << ans;
}