#include <bits/stdc++.h>
using namespace std;
int main() {
    int h,m,a;
    cin >> h >> m >> a;
    int ah = a / 60;
    int am = a % 60;
    m += am;
    h += ah;
    h += m / 60;
    m %= 60;
    h %= 24;
    cout << h << " " << m;
}