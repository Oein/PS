#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll b1 = 23, b2 = 59, b3 = 17;
const ll p1 = 1e9+7, p2 = 1e9+9, p3 = 1e9-63;

struct Hash{
	ll a, b, c;

	bool operator == (Hash &x){
		return a == x.a && b == x.b && c == x.c;
	}
	bool operator < (const Hash &x)const{
		if(a != x.a) return a < x.a;
		if(b != x.b) return b < x.b;
		return c < x.c;
	}
};

vector<Hash> arr;
vector<string> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; v.resize(n); arr.resize(n+1);
	for(int i=0; i<n; i++) cin >> v[i];
	int len = v[0].size();

	int cnt = 0;

	for(int i=len-1; i>=0; i--){
		set<Hash> s;
		cnt++;
		for(int j=0; j<n; j++){
			arr[j].a = (arr[j].a * b1 + v[j][i]) % p1;
			arr[j].b = (arr[j].b * b2 + v[j][i]) % p2;
			arr[j].c = (arr[j].c * b3 + v[j][i]) % p3;
			s.insert(arr[j]);
		}
		if(s.size() == n){
			cout << cnt; return 0;
		}
	}
}