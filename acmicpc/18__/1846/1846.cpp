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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    if(n == 3) {
        cout << "-1";
        return 0;
    }
    int secSL = n / 2 + (n % 2);
    int secSR = n / 2;

    cout << secSL << "\n";
    for(int i = 1;i < secSL;i++){
        cout << i << "\n";
    }
    cout << n << "\n";
    for(int i = 1;i < secSR;i++){
        cout << i + secSL << "\n";
    }
}