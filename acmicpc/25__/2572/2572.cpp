#include <bits/stdc++.h>

using namespace std;

const int MAX = 500;
const int CARD_MAX = 1000;

vector<pair<int, char>> adj[MAX + 1];
char card[CARD_MAX];
int costMap[CARD_MAX + 1][MAX + 1];
int n, m, k;

int max(int a, int b)
{
	return a > b ? a : b;
}

int func(int turn, int point)
{
	if (turn == n)
		return 0;

	int& res = costMap[turn][point];

	if (res != -1)
		return res;

	res = 0;

	for (auto vertex : adj[point])
	{
		int next = vertex.first;
		res = max(res, func(turn + 1, next) + (vertex.second == card[turn] ? 10 : 0));
	}

	return res;
}

int main()
{
	memset(costMap, -1, sizeof(costMap));

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf(" %c", &card[i]);

	scanf("%d %d", &m, &k);

	for (int i = 0; i < k; i++)
	{
		int x, y;
		char color;

		scanf("%d %d %c", &x, &y, &color);
		adj[x].push_back(make_pair(y, color));
		adj[y].push_back(make_pair(x, color));
	}

	printf("%d",func(0, 1));

	return 0;
}