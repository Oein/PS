#include <iostream>
using namespace std;
int ba[105];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        for(int j = a; j <= b;j++) ba[j] = c;
    }
    for(int i = 0;i < n;i++) cout << ba[i] << " ";
}