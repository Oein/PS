#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int , int> pi_i;
typedef pair<pair<int , int> , pair<int , int>> ppi_i__pi_i;
typedef pair<long long , long long> pll_ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> ms_i;
typedef map<string , string> ms_s;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

int n;
vector<int> able;
bool exsist[1000005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        exsist[a] = true;
        able.push_back(a);
    }

    ll ans = 0;

    for(int j = 0;j < n;j++){
        // 2ax + x^2 = c^2 - a^2
        // 2ax + x^2 = b
        // (x + a)^2 == 무언가의 ^ 2
        int a = able[j];
        for(
            ll x = 1 , temp = 2 * x * a + x * x;
            temp <= 1000000; 
            x++,temp=2 * x * a + x * x
        ){
            if(exsist[temp]){
                // cout << "\na : " << a;
                // cout << "\nb : " << b;
                // cout << "\nx : " << x;
                // cout << "\n-----------------";
                ans++;
            }
        }
    }

    cout << ans;
}