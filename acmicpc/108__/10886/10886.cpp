#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N = 0, g = 0, b = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		bool z=0;
		cin >> z;
		if (z) {
			g++;
		}
		else {
			b++;
		}
	}
	if (g > b) {
		cout << "Junhee is cute!";
	}
	else
	{
		{
			cout << "Junhee is not cute!";
		}
	}
}