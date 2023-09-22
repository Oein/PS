#include <iostream>
using namespace std;
int main(void)
{
	int n, an, bn;
	cin >> n;
	while (n--)
	{
		int tmp, a[5] = { 0, }, b[5] = { 0, };
		cin >> an;
		for (int i = 0; i < an; i++)
		{
			cin >> tmp;
			a[tmp]++;
		}
		cin >> bn;
		for (int i = 0; i < bn; i++)
		{
			cin >> tmp;
			b[tmp]++;
		}
		int k = 4;
		int who = 0;
		for (int i = 4; i >= 1; i--)
		{
			if (a[i] > b[i])
				who = 1;
			else if (a[i] < b[i])
				who = 2;
			if (who != 0)
				break;
		}

		if (who == 0)
			cout << "D\n";
		else if (who == 1)
			cout << "A\n";
		else if (who == 2)
			cout << "B\n";
	}
}