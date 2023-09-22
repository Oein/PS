#include <iostream>
#include <string>

using namespace std;


int main() {
	string d = "";
	cin >> d;

	for (int i = 'a'; i < 'a' + 26; i++) {
		if (d.find(i) == string::npos) {
			cout << "-1 ";
		}
		else {
			cout << d.find(i) << " ";
		}
	}
}