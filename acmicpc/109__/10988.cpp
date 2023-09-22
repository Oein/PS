#include <iostream>
using namespace std;
int main() {
    string x;
    cin >> x;
    for(int i = 0;i < x.size() / 2;i++) {
        if(x[i] != x[x.size() - 1 - i]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}