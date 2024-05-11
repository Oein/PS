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

int c[10005] , y[10005];

int main(){
    cin.tie(0); cout.tie(0);
    int n , s , nPrice , storePrice;
    cin >> n >> s;
    for(int i = 0;i < n;i++) cin >> c[i] >> y[i];

    ll ans = c[0] * y[0]; // 첫주는 그냥 바로 사야됨
    nPrice = c[0];
    storePrice = s;

    for (int i = 1; i < n; i++)
	{
        // 현재 가격에 + 보관비용 < 다음 주 가격
		if (nPrice + storePrice < c[i])
		{
			ans = ans + nPrice * y[i] + y[i] * storePrice;
			storePrice = storePrice + s;
		}
		else
		{
			ans = ans + c[i] * y[i];
			nPrice = c[i];
			storePrice = s;
		}	
	}

    cout << ans;
}