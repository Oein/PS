#include <iostream> 
#include <vector>
using namespace std; 

int main() {
    int n = 0, sum = 0;
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        sum = sum + i;
    }
    cout << sum;
}
