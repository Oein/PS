#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X[100001];
ll nd[100001]; // 지금까지 거리
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	ll R, L, B; 
	cin >> R >> L >> B;

	for (int i = 1; i <= R;i++) {
		cin >> X[i];
		nd[i] = nd[i - 1] + X[i];
	}

	int ans = 0;
	for (int i = 1; i <= R; i++) {
		int s = i;
		int e = R;
		while (s <= e) {
			int mid = (s + e) / 2;
			int k = (i + mid) / 2;
			ll tmp = 0;
			tmp += nd[mid] - nd[k] - (X[k] * (mid - k)); //right money
			tmp += X[k] * (k - i) - (nd[k - 1] - nd[i - 1]); //left money
			if (tmp <= B) { // 더 적게 사용이 가능하다?
				ans = max(ans, mid - i + 1); // ans 는 트럭 계수지 money가 아니다. (주의하자)
				s = mid + 1;
			}
			else e = mid - 1;
		}
	}
	cout << ans;
}