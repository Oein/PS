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

int dp[505][505][2];
// dp[first bukkit][second bukkit][hwo]

int get_[4];

// 0 is A , 1  is B
bool getAWin(int fb , int sb , bool who){
    if(dp[fb][sb][who] != -1) return dp[fb][sb][who];

    for(int i = 0;i < 3;i++){ // 첫번째꺼를 먹는다
        if(get_[i] <= fb && !getAWin(fb - get_[i] , sb , !who)){
            dp[fb][sb][who] = 1;
            return true;
        }
    }

    for(int i = 0;i < 3;i++){ // 두번째꺼를 먹는다
        if(get_[i] <= sb && !getAWin(fb , sb - get_[i] , !who)){
            dp[fb][sb][who] = 1;
            return true;
        }
    }

    dp[fb][sb][who] = 0;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> get_[0] >> get_[1] >> get_[2];
    for(int i = 0;i < 5;i++){
        memset(dp , -1 , sizeof(dp));
        int f,s;
        cin >>f >> s;
        if(getAWin(f , s , 0)) cout << "A\n";
        else cout << "B\n";
    }
}