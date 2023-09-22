#include<iostream>
using namespace std;
using int64 = long long int;

int64 maxrepuest = 0;
int64 s = 0;
int64 e = 0;
int N = 0;
int* request = new int[10000];
int64 M = 0;

int64 f(int64 limit) {
	int64 total = 0;
	for (int i = 0; i < N; i++) {
		if (request[i] <= limit) total += request[i];
		else total += limit;
	}
	return total;
}

bool test(int64 limit) {
	if (f(limit) > M) return false;
	else return true;
}

int main() {
	

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> request[i];
		if (request[i] > maxrepuest)maxrepuest = request[i];
	}
	cin >> M;
	e = maxrepuest + 1;
	int64 ret = 0;
	while (s < e)
	{
		int64 mid = (s + e) / 2;
		
		if (test(mid)) {
			ret = mid;
			s = mid + 1;
		}
		else
		{
			e = mid;
		}

	}
	cout << ret;
}