#include <iostream>
using namespace std;
bool isSelf[10005];
int d(int n) {
    int ret = n;
    while(n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
int main() {
    for(int i = 1; i <= 10000;i++) {
        if(isSelf[i]) continue;
        int r = d(i);
        while(r <= 10000 && isSelf[r] == false) {
            isSelf[r] = 1;
            r = d(r);
        }
    }
    for(int i = 1;i <= 10000;i++) {
        if(isSelf[i] == 0) cout << i << "\n";
    }
}
