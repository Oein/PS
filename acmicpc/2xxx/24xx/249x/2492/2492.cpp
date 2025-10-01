#include <bits/stdc++.h>

using namespace std;

struct Pos {
	int x = 0;
	int y = 0;
};

vector<Pos> ores;

int count_of_ore = 0;
int size_of_square = 0;

int count_of_ores(int x, int y) {
	int ans = 0;

	for (int i = 0; i < count_of_ore; i++) {
		Pos now = ores[i];
		if (now.x >= x && now.x <= size_of_square + x && now.y <= y && now.y >= y - size_of_square) {
			ans++;
		}
	}

	return ans;
}

int main() {
	int x_of_map = 0;
	int y_of_map = 0;

	cin >> x_of_map >> y_of_map >> count_of_ore >> size_of_square;

	for (int i = 0; i < count_of_ore; i++) {
		Pos ore;
		cin >> ore.x >> ore.y;
		ores.push_back(ore);
	}

	int ans_x = -1;
	int ans_y = -1;
	int ans = -1;

	for (int i = 0; i < count_of_ore; i++) {
		for (int j = 0; j < count_of_ore; j++) {
			Pos ore1 = ores[i];
			Pos ore2 = ores[j];

			int square_x = (ore1.x > ore2.x) ? ore2.x : ore1.x;
			int square_y = (ore1.y > ore2.y) ? ore1.y : ore2.y;

			int count = count_of_ores(square_x, square_y);
			if (count > ans) {
				ans = count;
				ans_x = square_x;
				ans_y = square_y;
			}
		}
	}

	if (ans_x + size_of_square > x_of_map) {
		ans_x = x_of_map - size_of_square;
	}

	if (ans_y - size_of_square < 0) {
		ans_y = size_of_square;
	}

	cout << ans_x << " " << ans_y << "\n" << ans;
}