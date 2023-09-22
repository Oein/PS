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

#define MAXN 100005

vector<int> paths[MAXN];
int ina[MAXN] , inb[MAXN] , froma[MAXN] , fromb[MAXN];

set<int> used;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> ina[i];
        froma[ina[i]] = i;
    }
    for(int i = 1;i <= n;i++){
        cin >> inb[i];
        fromb[inb[i]] = i;
    }

    // froma[?] == 0 && fromb[?] == 0
    // 이면 항상 root

    for(int i = 1;i <= n;i++){
        if(froma[i] == 0 && fromb[i] == 0){
            int nowa = i, nowb = i;
            while(nowa == nowb && nowa != 0){
                used.insert(nowa);
                nowa = ina[nowa];
                nowb = inb[nowb];
            }
        }
    }
        
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(used.find(i) == used.end()){ // root 가 아니면
            // 전놈이 있다? 그럼 자신이 옮겨진다 이소리임
            ans += (froma[i] != 0) ? 1 : 0; // 전놈이 있다 ? 1 : 0
            ans += (fromb[i] != 0) ? 1 : 0; // 전놈이 있다 ? 1 : 0
        }
    }
    cout << ans;
}