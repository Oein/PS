#include <iostream> 
#include <vector>
using namespace std; 

int main() {
    int x = 0;
    vector<int> a;
    vector<int> b;
    cin >> x;
    for (int i = 0; i < x; i++) {
        int ax = 0,bx = 0;
        cin >> ax >> bx;
        a.push_back(ax);
        b.push_back(bx);
    }
    for (int i = 0; i < x; i++) {
        cout << a[i] + b[i] << '\n';
    }
}
