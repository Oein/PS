#include <iostream> 
#include <algorithm>
using namespace std; 

int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int num[1000] = { 9999, };
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int number = 0;
        cin >> number;
        num[i] = number;
    }
    sort(num, num + n);
    for (int i = 0; i < n; i++) {
        cout << num[i] << '\n';
    }
}
