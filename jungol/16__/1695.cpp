#include <bits/stdc++.h>
using namespace std;
int n = 0;
int danzi = 0;

class cell
{
public:
	int y;
	int x;
	cell(int _y, int _x)
	{
		y = _y;
		x = _x;
	}
};

int main()
{
	cin >> n;
	int M[25][25];
	memset(M, 0, sizeof M);
	vector<int> cnt; // count.

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			char c;
			cin >> c;
			if (c == '0')
				M[y][x] = 0;
			else
				M[y][x] = 1;
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (M[y][x] == 1)
			{
				// 퍼진다
				M[y][x] = 2;
				danzi++;

				queue<cell> q;
				q.push(cell(y, x));
				int count = 0;
				while (!q.empty())
				{
					cell now = q.front();
					q.pop();
					count++;

					//! 위 체크.
					if ((now.y != 0) && (M[now.y - 1][now.x] == 1))
					{
						q.push(cell(now.y - 1, now.x));
						M[now.y - 1][now.x] = 2;
					}

					//! 오른쪽 체크.
					if ((now.x != n - 1) && (M[now.y][now.x + 1] == 1))
					{
						q.push(cell(now.y, now.x + 1));
						M[now.y][now.x + 1] = 2;
					}

					//! 아래 체크.
					if ((now.y != n - 1) && (M[now.y + 1][now.x] == 1))
					{
						q.push(cell(now.y + 1, now.x));
						M[now.y + 1][now.x] = 2;
					}

					//! 왼쪽 체크.
					if ((now.x != 0) && (M[now.y][now.x - 1] == 1))
					{
						q.push(cell(now.y, now.x - 1));
						M[now.y][now.x - 1] = 2;
					}
				}
				cnt.push_back(count);
			}
		}
	}

	cout << danzi << '\n';
	sort(cnt.begin(), cnt.end());
	for (int i = 0; i < cnt.size(); i++)
	{
		cout << cnt[i] << '\n';
	}
	return 0;
}