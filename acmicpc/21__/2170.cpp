#include <bits/stdc++.h>

using namespace std;

// bool debug = false;

struct Pos {
	int start = 0;
	int end = 0;
};

vector<Pos> lines;

bool sort_function(Pos a, Pos b) {
	return a.start < b.start;
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int count_of_line = 0; // N (최대 1 000 000)
	cin >> count_of_line;

	for (int i = 0; i < count_of_line; i++) {
		Pos pos;
		cin >> pos.start >> pos.end;

		lines.push_back(pos);
	}

	sort(lines.begin(), lines.end(), sort_function);

	long long int ans = 0;

	int left = INT_MIN;
	int right = INT_MIN;

	for (int i = 0; i < count_of_line; i++) {
		int start_pos = lines[i].start;
		int end_pos = lines[i].end;

		if (start_pos >= left && start_pos <= right) {
			// if(debug) cout << "In between " << left << "  " << right << "\n";
			if(end_pos > right) right = end_pos;
		}
		else {
			ans += right - left;
			// if (debug) cout << "Add " << right - left << "\n";
			left = start_pos;
			right = end_pos;
		}
	}

	ans += right - left;
	// if (debug) cout << "Add " << right - left << "\n";

	cout << ans;
}