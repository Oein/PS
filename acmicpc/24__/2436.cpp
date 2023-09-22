#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

ll G, L;
ll ab;

ll resA, resB;

int main() {
    cin >> G >> L;
    ab = L / G;
    
    for(ll a = 1; a * a <= ab;a++) {
        if(ab % a) continue;
        
        ll b = ab / a;
        
        bool able = true;
        ll cnt = 0;
        for (long long int j = 1; j <= a; j++) {
            if (a % j == 0 && b % j == 0) {
                cnt++;
            }
            
            if (cnt > 1) {
                able = false;
            }
        }

        if (able) {
            resA = a * G;
            resB = b * G;
        }
    }
    
    cout << resA << " " << resB;
}


/*
 n | A B
---------
     a b
 
 b = m/n/a;
 na  = A;
m / a  = B;
 
 m / a = B
 n * a = A
 
 
 */
