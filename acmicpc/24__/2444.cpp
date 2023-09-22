#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
  
    for (int i = 0; i < x; ++i) {
       for (int k = x - i - 1; k > 0; --k) {
          cout << " ";
       }
       for (int j = x+i*2; j >= x; --j) {
          cout << "*";
       }
       cout << "\n";
    }
    for (int i = 1; i < x; ++i) {
       for (int k = x - i ; k < x; ++k) {
          cout << " ";
       }
       for (int j = -x + i*2 +1; j < x; ++j) {
          cout << "*";
       }
       cout << "\n";
    }
}
