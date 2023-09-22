#include <bits/stdc++.h>

using namespace std;

int main() {
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string input = "";
		stack<string> stak;

		cin >> input;

		bool no = false;

		for (int j = 0; j < input.size(); j++) {
			if (input[j] == '(') {
				stak.push("(");
			}
			else if (input[j] == ')') {
				if (stak.empty() == true) {
					no = true;
					continue;
				}
				else {
					stak.pop();
				}
			}
		}

		if (stak.empty() == false) no = true;

		if (no) cout << "NO\n";
		else cout << "YES\n";
	}
}