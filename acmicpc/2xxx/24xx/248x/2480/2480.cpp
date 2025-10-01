#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if(a == b && b == c) {
        cout << 10000+a*1000;
        return 0;
    }
    if(a == b) {
        cout << 1000+a*100;
        return 0;
    }
    if(a == c) {
        cout << 1000+a*100;
        return 0;
    }
    if(c == b) {
        cout << 1000+b*100;
        return 0;
    }
    cout << max(max(a,b),c) * 100;
}