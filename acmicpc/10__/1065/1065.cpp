#include <iostream>
using namespace std;
bool isHan(int n) {
    if(n < 100) return true;
    if(n == 1000) return false;
    // n 은 항상 3 자리
    int dif = n % 10;
    n /= 10;
    dif = (dif - (n % 10));
    int difa = n % 10;
    n /= 10;
    difa = (difa - (n));
    return dif == difa;
}
int main() {
    int n, ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        if(isHan(i)) ans++;
    }
    cout << ans;
}
