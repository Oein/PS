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

string pattern;
int n;

int main(){
    cin.tie(0); cout.tie(0);
    cin >> pattern >> n;
    int ans = 0;
    for(int i = 0;i < n;i++){
        string ring;
        cin >> ring;
        bool ok = false;
        for(int j = 0;j < ring.size();j++){
            bool okNow = true;
            for(int k = 0;k < pattern.size();k++){
                if(ring[(j + k) % ring.size()] != pattern[k]){
                    okNow = false;
                    break;
                }
            }
            if(okNow) {
                ok = true;
                break;
            }
        }
        if(ok) ans++;
    }

    cout << ans;
}