#include <bits/stdc++.h>

using namespace std;

int casex[] = { 2 , 1 , 2 , 3 , 1 , 2 , 3 , 1 , 2 , 3 };
int casey[] = { 4 , 1 , 1 , 1 , 2 , 2 , 2 , 3 , 3 , 3 };

int effort(int a, int b) {
	return abs(casex[a] - casex[b]) + abs(casey[a] - casey[b]);
}

string zero_pad(int x) {
	if (x <= 9) return "0" + to_string(x);
	else return to_string(x);
}

int effort_hm(int hx, int mx) {
	string h = zero_pad(hx);
	string m = zero_pad(mx);

	int result = 0;
	result += effort(h[0] - '0', h[0] - '0');
	result += effort(h[0] - '0', h[1] - '0');
	result += effort(m[0] - '0', h[1] - '0');
	result += effort(m[1] - '0', m[0] - '0');

	return result;
}

vector<int> hours;
vector<int> minutes;

int main() {
	int hour = 0;
	char middle = ':';
	int minute = 0;
	cin >> hour >> middle >> minute;

	for (int i = hour; i <= 100; i += 24) {
		hours.push_back(i);
	}
	for (int i = minute; i <= 100; i += 60) {
		minutes.push_back(i);
	}

	int low = 123456789;
	string low_x = "99:99";

	for (int i = 0; i < hours.size(); i++) {
		int h = hours[i];
		for (int j = 0; j < minutes.size(); j++) {
			int m = minutes[j];

			int effort_ = effort_hm(h, m);
			if (effort_ < low) {
				low = effort_;
				low_x = zero_pad(h) + ":" + zero_pad(m);
			}
		}
	}

	cout << low_x;
}