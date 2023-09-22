#include <iostream>
using namespace std;
int ba[105];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) ba[i] = i;
    for(int i = 0;i < m;i++) {
        int a,b;
        cin >> a >> b;
        swap(ba[a], ba[b]);
    }
    for(int i = 1;i <= n;i++) cout << ba[i] << " ";
}