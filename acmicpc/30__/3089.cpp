#define MAX 100000
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> cx[2 * MAX], cy[2 * MAX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, order, x, y, ex = MAX, ey = MAX, ty, tx;

	cin >> num >> order;
	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		cy[y + MAX].push_back(x + MAX);
		cx[x + MAX].push_back(y + MAX);
	}
	for (int i = 0; i < 2 * MAX; i++) {
		if (cy[i].size() > 0)	sort(cy[i].begin(), cy[i].end());
		if (cx[i].size() > 0)	sort(cx[i].begin(), cx[i].end());
	}
	char c;
	for (int i = 0; i < order; i++) {
		cin >> c;
		if (c == 'U') {		//x값은 같다
			ty = 2 * MAX + 1;
			tx = ex;
			for (int j = 0; j < cx[ex].size(); j++) {
				int ny = cx[ex][j];
				if (ny > ey) { 		
					ty = ny;
					break;
				}
			}
			ex = tx; ey = ty;
		}
		else if (c == 'D') {
			ty = 0;
			tx = ex;
			for (int j = cx[ex].size()-1; j >=0; j--) {
				int ny = cx[ex][j];
				if (ny < ey) {		
					ty = ny;
					break;
				}
			}
			ex = tx; ey = ty;
		}
		else if (c == 'L') {
			ty = ey;
			tx = 0;
			for (int j = cy[ey].size()-1; j>=0; j--) {
				int nx = cy[ey][j];
				if (nx < ex) {
					tx = nx;
					break;				
				}
			}
			ex = tx; ey = ty;
		}
		else if (c == 'R') {
			ty = ey;
			tx = 2 * MAX + 1;
			for (int j = 0; j < cy[ey].size(); j++) {
				int nx = cy[ey][j];
				if (nx > ex) {
					tx = nx;
					break;					
				}
			}
			ex = tx; ey = ty;
		}
	}
	cout << ex - MAX << " " << ey - MAX;
	return 0;
}