#include <bits/stdc++.h>

using namespace std;

int n, R, m;
vector<int> v;
vector<int> lens;
vector<int> moves;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> R >> m;
	v.resize(n);
  lens.resize(n);
  moves.resize(n * 2 + 1);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    lens[i] = (v[(i + 1) % n] - v[i] + m) % m;
  }

  for (int i = 0; i < n; i++) {
    moves[i] = moves[i + n] = lens[i] - R * 2;
  }

  int s = 0, ans = 0;
  for(int i = 0; i < moves.size(); i++) {
    s += moves[i];
    if(s < 0) s = 0;
    ans = max(ans, s);
  }
  cout << (ans + 1) / 2;
	return 0;
}