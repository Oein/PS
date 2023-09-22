#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, x, y, w, h;
    cin >> N;

    vector<vector<int>> plane(1001, vector<int>(1001, 0));
    vector<pair<pair<int, int>, pair<int, int>>> papers(N);

    for (int i = 0; i < N; ++i) {
        cin >> x >> y >> w >> h;
        papers[i] = {{x, y}, {w, h}};
        for (int j = x; j < x + w; ++j) {
            for (int k = y; k < y + h; ++k) {
                plane[j][k] = i + 1;
            }
        }
    }

    vector<int> visible_area(N, 0);
    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j < 1001; ++j) {
            if (plane[i][j]) {
                visible_area[plane[i][j] - 1]++;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << visible_area[i] << endl;
    }

    return 0;
}
