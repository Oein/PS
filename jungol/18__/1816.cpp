#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int , int> pi_i;

int arr[201];
int arrTwo[201];
int m, s, c, ans;

int main()
{
	cin >> m >> s >> c;


	for (int i = 0; i < c; i++)
	{
		cin >> arr[i];

	}

	sort(arr, arr + c);

	for (int i = 0; i < c - 1; i++)
	{
		arrTwo[i] = arr[i + 1] - arr[i];
	}

	sort(arrTwo, arrTwo + c);

	for (int i = 0; i < c - m + 1; i++)
	{
		ans += arrTwo[i];
	}

	if (m >= c)
		cout << c;
	else
		cout << ans + m;
}