#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, K;
int st, ed;
string doAble[1010];
bool did[1010];

bool Find(string a, string b) {
	int dif = 0;
	for (int i = 0; i < K; i++) {
		if (a[i] != b[i]) {
			dif++;
			if (dif > 1) return false;
		}
	}
	if (dif == 1) return true;
	return false;
}

struct qdata {
	string n;
	queue<int> way;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> doAble[i];
	}

	cin >> st >> ed;

	queue<qdata> q;
	qdata qd;
	qd.n = doAble[st];
	qd.way.push(st);
	q.push(qd);

	while (!q.empty()) {
		qdata qdt = q.front();
		q.pop();
		if (qdt.n == doAble[ed]) {
			while (!qdt.way.empty()) {
				cout << qdt.way.front() << " ";
				qdt.way.pop();
			}
			return 0;
		}
		for (int i = 1; i <= N; i++) {
			if (Find(doAble[i], qdt.n) && did[i] == false) {
				did[i] = true;
				qdata nqd;
				nqd.n = doAble[i];
				nqd.way = qdt.way;
				nqd.way.push(i);
				q.push(nqd);
			}
		}
	}

	cout << "-1";
}