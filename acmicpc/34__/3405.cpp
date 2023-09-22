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

#define MAXNAR 21
int n;
int beet[MAXNAR][MAXNAR]; // 빛
vector<bool> vis(1 << (MAXNAR - 5)),okKingDom(20);

int countOfByeBye(int bit){
    int ret = 0;
    for(int i = 0;i < n;i++){
        ret += (bit & (1 << i)) ? 1 : 0;
    }

    return ret;
}

int getNotByeByeKingDom(int bit){
    for(int i = 0;i < n;i++){
        if(!(bit & (1 << i))) return i;
    }
    return -1;
}

bool canByeBye(int bit , int how){
    int mn = 0;
    for(int i = 0;i < n;i++){
        if(!(bit & (1 << i))){
            mn += beet[how][i];
        }
    }

    return mn <= 0;
}

// 0 = 안망함 , 1 = 망함
void dfs(int bit){
    if(vis[bit]) return;
    vis[bit] = true;

    if(countOfByeBye(bit) >= n - 1){
        okKingDom[getNotByeByeKingDom(bit)] = true;
        return;
    }

    for(int i = 0;i < n;i++){
        if(bit & (1 << i)) continue;
        if(canByeBye(bit , i)) continue;
        dfs(bit ^ (1 << i));
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cin >> beet[i][j];
            }
        }

        okKingDom.assign(20 , false);
        vis.assign(1 << n , false);

        dfs(0);
        bool found = false;
        for(int i = 0;i < n;i++){
            if(okKingDom[i]){
                cout << i + 1 << " ";
                found = true;
            }
        }
        if(!found) cout << "0";
        cout << "\n";
    }
}