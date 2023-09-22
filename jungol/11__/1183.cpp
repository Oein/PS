#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pii;

/**
2679원이 있음
   13원을 만들어야됨 (가장 동전을 많이 사용해서 (많이 쓰는 코드는 WA 인디))
		  (근디 지금은 가장 적게 사용하는건디... (이 코드 자체는 맞는뎅) -> 응용 해야됨)

13은 항상 만들수 있다.
2666또한 항상 만들수 있다?
**/

int main(){
    int w , ansCnt = 0 , money = 0;
    int cnt[10];
    int price[10] = {500,100,50,10,5,1};
    int used[10];
    cin >> w >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3] >> cnt[4] >> cnt[5];

    for(int i = 0;i < 6;i++) money += cnt[i] * price[i];

    w = money - w;

    for(int i = 0;i < 6;i++){
        int useCoinCount = min(cnt[i] , w / price[i]);
        used[i] = useCoinCount;
        ansCnt += useCoinCount;
        w -= useCoinCount * price[i];
    }

    cout << (cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5]) - ansCnt << "\n";
    for(int i = 0;i < 6;i++){
        cout << cnt[i] - used[i] << " ";
    }
}
