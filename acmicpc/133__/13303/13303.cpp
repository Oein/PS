#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, sty, enx;
typedef long long ll;

struct Line {
    int x;
    int low_y;
    int high_y;
};

struct Data {
    int y;
    int sm;
};

bool cmp(Line a, Line b) {
    return a.x < b.x;
}

vector<Line> lines;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> sty >> enx;
    for (int i = 0; i < n; i++) {
        int lx;
        int lys;
        int lye;
        cin >> lx >> lys >> lye;
        lines.push_back({ lx , lys , lye });
    }

    sort(lines.begin(), lines.end(), cmp);

    map<int, int> dt;
    dt[sty] = 0;
    const int INF = 4000000;
    for (auto ln : lines) {
        auto it = dt.lower_bound(ln.low_y);
        auto it_end = dt.upper_bound(ln.high_y);
        if (it == it_end) continue;
        int low_dist = INF;
        int high_dist = INF;
        for (; it != it_end; )
        {
            low_dist = min(low_dist , it->second + it->first - ln.low_y);

            high_dist = min(high_dist, it->second + ln.high_y - it->first);

            dt.erase(it++);
        }

        dt[ln.low_y] = low_dist;
        dt[ln.high_y] = high_dist;
    }

    int min_dist = INF;

    int count_of_low = 0;

    for (auto i : dt) {
        if (min_dist > i.second) {
            count_of_low = 1;
            min_dist = i.second;
        }
        else if (min_dist == i.second) {
            count_of_low++;
        }
    }

    cout << min_dist + enx << "\n" << count_of_low << " ";

    for (auto i : dt) {
        if (i.second == min_dist) {
            cout << i.first << " ";
        }
    }
}
