#include <bits/stdc++.h>
using namespace std;
int main() {
    bool g[10] = {0,};
    for(int i = 0;i < 5;i++) {
        int x;
        cin >> x;
        g[x] = !g[x];
    }
    for(int i = 0; i <= 9;i++) {
        if(g[i]) cout << i;
    }
}