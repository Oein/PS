#include <bits/stdc++.h>

using namespace std;

int main() {
	int n = 0;
	cin >> n;

	queue<int> que;

	for (int i = 1; i <= n; i++) {
		que.push(i);
	}

	while (que.size() != 1)
	{
		que.pop();

		que.push(que.front());
		que.pop();
	}

	cout << que.front();
	return 0;
}