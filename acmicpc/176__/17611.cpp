// 저번에 파이프? 선분? 뭐 많이 겹치는거 2차원 버전이네 ㅋ

#include <bits/stdc++.h>
using namespace std;

int xs[1010101];
int ys[1010101];
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n; 
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		v[i].first += 500005; // 마이너스 없엘려고
		v[i].second += 500005;
	}

	for (int i = 0; i < n; i++) {
		pair<int, int> now = v[i];
		pair<int, int> nxt = v[(i + 1) % n];
		if (now.second == nxt.second) { // y가 같으면
			xs[min(now.first, nxt.first)]++;
			xs[max(now.first, nxt.first)]--;
		}
		else { // x 가 같으면
			ys[min(now.second, nxt.second)]++;
			ys[max(now.second, nxt.second)]--;
		}
	}

	for (int i = 1; i < 1010101; i++) {
		xs[i] += xs[i - 1];
		ys[i] += ys[i - 1];
	}

	sort(xs, xs + 1010101);
	sort(ys, ys + 1010101);

	int ans = max(xs[1010100] , ys[1010100]);
	cout << ans << "\n";
}