#include <iostream>
using namespace std;
using ll = long long;
long long check[10];

void calc(ll n, ll ten)
{
	while (n > 0) {
		check[n % 10] += ten;
		n /= 10;
	}
}

void solve(ll A, ll B, ll ten) {
	while (A % 10 != 0 && A <= B)
	{
		calc(A, ten);
		A++;
	}
	if (A > B) return;
    
	while (B % 10 != 9 && B >= A)
	{
		calc(B, ten);
		B--;
	}
	ll cnt = (B / 10 - A / 10 + 1);
	for (int i = 0; i < 10; ++i)
		check[i] += cnt * ten;
	solve(A / 10, B / 10, ten * 10);
}

int main()
{
	ll n;
	cin >> n;
	solve(1, n, 1);

	for (int i = 0; i < 10; ++i)
		cout << check[i] << " ";
}