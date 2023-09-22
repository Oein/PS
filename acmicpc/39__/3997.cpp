#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

map<ll,ll> mp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n = 0;
    cin >> n;

    ll ans = 0;
    ll x = 0;

    string s;
    cin >> s;

    mp[0] = 1LL;

    for(int i = 0;i < n;i++){
        int alphaI = s[i] - 'A' - (s[i] >= 'a' ? 6 : 0);
        // (s[i] >= 'a' ? 6 : 0)
        //      = 소문자
        // ascii 에서 대문자 < 소문자
        x ^= (1LL << alphaI); // ^ = xor

        ans += mp[x];

        for(int j = 0;j< 52; j++){ // 하나만 바뀌는 경우
			if(mp.find( x ^ ( 1LL<<j ) ) != mp.end()) 
                ans += mp[ x ^ ( 1LL << j ) ];
		}

		mp[x]++;
    }

    cout << ans;
}