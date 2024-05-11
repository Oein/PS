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

int main(){
    cin.tie(0); cout.tie(0);
    int chuCount[6];
    int n , cnt = 0;
    cin >> chuCount[0] >> chuCount[1] >> chuCount[2] >> chuCount[3] >> chuCount[4] >> n;

    int chuWei[] = {1,2,4,8,16};
    for(int i = 4;i >= 0;i--){
        while(n >= chuWei[i] && chuCount[i] > 0){
            n -= chuWei[i];
            chuCount[i]--;
            cnt++;
        }
    }

    if(n) cout << "impossible";
    else cout << cnt;
}