#include <iostream>
using namespace std;

int N;//나무의 수
int M;//가져갈 나무의 길이
int* tree = new int[1000000];
bool test(int x)
{

	long long total = 0;
	for (int i = 0; i < N; i++)
	{
		if (x < tree[i]) total += ((long long)tree[i] - x);
		if (total >= M)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int bigtree=0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		if (tree[i] > bigtree)
		{
			bigtree = tree[i];
		}
	}


	int s = 0;
	int e = bigtree;
	int mid;
	int last = -1;
	while (s < e)
	{
		mid = (s + e) / 2;
		if (test(mid))
		{
			// true.
			s = mid + 1;
			if (last < mid)
			{
				last = mid;
			}
		}
		else {
			// false.
			e = mid;
		}
	}
	cout << last <<'\n';
}