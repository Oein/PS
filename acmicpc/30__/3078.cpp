#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>

using namespace std;

vector<int> list[22];
int last_friend_idx_in_list[22] = {0,};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n = 0; // number of friends
    int k = 0; // max differ a score and b score
    
    cin >> n >> k;
    long long int ans = 0;
    
    for(int i = 1;i <= n;i++){
        string name;
        cin >> name;
        list[name.size()].push_back(i);
        
        int nl = name.size();
        int lnl = list[nl].size();
        bool con = false;
        
        while (i - list[nl][last_friend_idx_in_list[nl]] > k) {
            last_friend_idx_in_list[nl]++;
            if(last_friend_idx_in_list[nl] == lnl){
                con = true;
                break;
            }
        }
        
        if(con) continue;
        
        ans += lnl - last_friend_idx_in_list[nl] - 1;
    }

    cout << ans;
    
    /*
     자기 보다 등수가 높고 차이가 k 초과 안남
     이름 수가 같음
     
     이름끼리 넣고
     해보자
     */
}
