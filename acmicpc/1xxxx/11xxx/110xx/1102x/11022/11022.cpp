#include <iostream> 
#include <vector>
using namespace std; 

int main() {
    int n = 0;
    vector<int>as;
    vector<int>bs;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        as.push_back(a);
        bs.push_back(b);
    }
    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": " << as[i] << " + " <<  + bs[i] << " = " << as[i] + bs[i] << '\n';
    }
}
