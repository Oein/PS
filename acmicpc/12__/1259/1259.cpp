#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string x;
    cin >> x;
    while(x != "0") {
        bool ty = false;
        if(x.size() == 1)
            ty = true;
        if(x.size() == 2) {
            if(x[0] == x[1]) ty = true;
        }
        if(x.size() == 3) {
            if(x[0] == x[2]) ty = true;
        }
        if(x.size() == 4) {
            if(x[0] == x[3] && x[1] == x[2]) ty = true;
        }
        if(x.size() == 5) {
            if(x[0] == x[4] && x[1] == x[3]) ty = true;
        }
        cout << (ty ? "yes\n" : "no\n");
        cin >> x;
    }
}
