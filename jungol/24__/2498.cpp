#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include <limits>
#include <string>
#include <cmath>
#include <stack>
#include <climits>
#include <queue>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll gcded, lcmed, ab;
    cin >> gcded >> lcmed;
    ab = lcmed / gcded;
    
    ll A = -1, B = -1, md = LLONG_MAX;
    for(int i = 1; i * i <= ab; i++) {
        if(lcmed%i != 0) continue;
        if((lcmed / i) % gcded != 0) continue;
        ll a = i * gcded;
        ll b = lcmed / i;
        if(abs(b - a) <= md && gcd(a, b) == gcded) {
            A = a;
            B = b;
            md = abs(a - b);
        }
    }
    cout << A << " " << B;
}
