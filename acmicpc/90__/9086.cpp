#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string x;
        cin >> x;
        cout << x[0] << x[x.size() - 1] <<"\n";
    }
}