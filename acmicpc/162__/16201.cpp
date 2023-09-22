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
typedef pair<int , int> pii;
typedef pair<pair<int , int> , pair<int , int>> ppiipii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> msi;
typedef map<string , string> mss;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

#define mod 1000000007LL

ll c , r;
ll lin = 1 , lic = 0;

// r is x , c is y
int k;

vector<pii> rights;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> r >> c >> k;

    for(int i = 0;i < k;i++){
        int x , y;
        cin >> y >> x;
        rights.push_back({x , y});
    }

    if(c % 2 == 1){
        lin = ((c) / 2 + 1) % mod;
    }
    lic = c / 2;

    sort(rights.begin() , rights.end() , [](pii a , pii b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    ll ans = 1;
    ll tileCount = 0;

    ll last_y = 1; 
    ll last_x = 1;  // last_x ~ now

    ll count_of_blank_line = 0;

    for(int i = 0;i < k;i++){
        pii now = rights[i];
        if(last_y < now.second){ // changed Line
            ll tic = (c - last_x + 1);
            if(last_x > 1 && tic % 2 == 1){
                ans = (ans * ((tic / 2) + 1LL)) % mod;
                last_y++;
                tileCount += tic / 2;
            }
            else if(last_x > 1){
                // no need blank
                tileCount += tic / 2;
                last_y++;
                last_x = 1;
            }

            if(last_y < now.second){
                count_of_blank_line += now.second - last_y;
            }

            last_y = now.second;

            last_x = 1;
        }

        // last_y = 위에줄 때문에 항상 맞음
        // last_x ~ now.x 까지 처리 하면 됨

        ll wid = now.first - last_x;
        if(wid % 2 == 1){
            ans = (ans * (wid / 2LL + 1LL)) % mod;
        }
        tileCount += wid / 2;

        last_x = now.first + 1;
    }

    if(last_x > 1){
        ll nct = (c - last_x + 1LL);
        tileCount += nct / 2LL;
        if(nct % 2 == 1){
            ans = (ans * (nct / 2LL + 1LL)) % mod;
        }
        last_y++;
    }

    ll ywid = r - last_y + 1LL;

    count_of_blank_line += ywid;

    tileCount += count_of_blank_line * lic;

    if(lin > 1){ // 한줄을 다 채웠을때 경우의 수가 늘어 나는 경우
        for(; count_of_blank_line > 0; count_of_blank_line /= 2){
            if(count_of_blank_line % 2 == 1){
                ans = ans * lin % mod;
            }

            lin = lin * lin % mod;
        }
    }

    // lin ^ count_of_blank_line

    
    
    cout << tileCount << " " << ans;
}