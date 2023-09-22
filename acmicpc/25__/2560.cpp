#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int main(){
    cin.tie(0); cout.tie(0);
    int a , b , d , n , ans = 1 , sum = 0;
    cin >> a >> b >> d >> n;
    vector<int> cut(n + 5);
    cut[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (i >= b) {
            sum -= cut[i - b];
            sum += 1000; // - 떄매
            sum %= 1000;
        }
        if (i >= a) {
            sum += cut[i - a];
            sum += 1000; // - 떄매
            sum %= 1000;
        }
        cut[i] = sum;
        ans += cut[i];
        if (i >= d) {
            ans -= cut[i - d];
            sum += 1000; // - 떄매
            sum %= 1000;
        }
    }
    cout << ans % 1000;
}


