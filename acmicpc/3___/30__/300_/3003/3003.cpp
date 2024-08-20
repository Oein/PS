#include <bits/stdc++.h>
using namespace std;
int a[] = {1,1,2,2,2,8};
int main() {
    for(int i = 0;i < 6;i++) {
        int x;
        cin >> x;
        cout << a[i] - x << " ";
    }
}