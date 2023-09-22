#include <bits/stdc++.h>

using namespace std;

int n, m; 
int notyet = 0;
int done = 0;
int day = 0;
vector<vector<int>> tomato;
queue<pair<int,int>> newOne;

bool checkOk(int i, int j) {
	if (i < 0 || i >= n)
		return false;
	if (j < 0 || j >= m)
		return false;
	return true;
}
void plust(int i, int j) {
	i--;
	if( checkOk(i,j) && tomato[i ][j] == 0){
		tomato[i][j] = 1;
		newOne.push(make_pair(i, j));
		notyet--;
	}
	i += 2;
	if (checkOk(i, j) && tomato[i][j] == 0) {
		tomato[i][j] = 1;
		newOne.push(make_pair(i, j));
		notyet--;
	}
	i--;
	j--;
	if (checkOk(i, j) && tomato[i][j] == 0) {
		tomato[i][j] = 1;
		newOne.push(make_pair(i, j));
		notyet--;
	}
	j += 2;
	if (checkOk(i, j) && tomato[i][j] == 0) {
		tomato[i][j] = 1;
		newOne.push(make_pair(i, j));
		notyet--;
	}
}
void bfs() {
	int tx, ty;
	done = newOne.size();
	for (int i = 0; i < done; i++) {
		tx = newOne.front().first;
		ty = newOne.front().second;
		newOne.pop();
		plust(tx, ty);
	}
	day++;
	if (!newOne.empty()) {
		bfs();
	}
}

int main() {
	int temp;
	cin >> m >> n;

	tomato.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp; 
			tomato[i][j] = temp;
			if (temp == 0)
				notyet ++;
			else if (temp == 1) {
				newOne.push(make_pair(i, j));
			}
		}
	}

	bfs();
	if (notyet != 0)
		cout << -1;
	else
		cout << day-1;
}