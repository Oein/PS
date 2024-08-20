#include <iostream> 
#include <vector>
using namespace std; 

int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int64_t n = 0;
    vector<int>as;
    vector<int>bs;
    cin >> n;
    for (int64_t i = 0; i < n;i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        as.push_back(a);
        bs.push_back(b);
    }
    for (int64_t i = 0; i < n; i++) {
        cout << as[i] + bs[i] << '\n';
    }
}
