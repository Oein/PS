#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> x;
vector<int> y;

int getDistance(int x_, int y_) {
	int d = 0;
	for (int i = 0; i < m; i++) {
		d += abs(x_ - x[i]);
		d += abs(y_ - y[i]);
	}

	return d;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x_, y_;
		cin >> x_ >> y_;
		x.push_back(x_);
		y.push_back(y_);
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int middle_x = x[x.size() / 2];
	int middle_y = y[y.size() / 2];

	cout << getDistance(middle_x, middle_y);
}