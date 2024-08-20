#include <iostream>
using namespace std;
int a[250005];
int main() {
    int n;
    cin >> n;
    int removed = 0;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        int toBe = i - removed + 1;
        if(a[i] != toBe) removed++;
    }
    cout << removed;
}
