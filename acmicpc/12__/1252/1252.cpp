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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string a , b , ans;
    int alen , blen;

    cin >> a >> b;

    alen = a.length();
    blen = b.length();

    int maxLen = max(alen , blen);

    bool goUp = 0;
    for(int i = 0;i < maxLen;i++){
        int aChar = 0;
        if(alen > i){
            aChar = a[alen - i - 1] - '0';
        }
        int bChar = 0;
        if(blen > i){
            bChar = b[blen - i - 1] - '0';
        }

        int add = aChar + bChar + (goUp ? 1 : 0);
        if(add == 0){
            ans += '0';
            goUp = false;
        }else if(add == 1){
            ans += '1';
            goUp = false;
        }else if(add == 2){
            ans += '0';
            goUp = true;
        }else if(add == 3){
            ans += '1';
            goUp = true;
        }
    }

    if(goUp){
        ans += '1';
    }

    // ans 거꾸로 출력

    bool starting = true;
    bool print = false;
    for(int i = ans.length() - 1;i >= 0;i--){
        if(starting){
            if(ans[i] == '0'){
                continue;
            }
            starting = false;
        }
        cout << ans[i];
        print = true;
    }
    if(!print) cout << "0";
}