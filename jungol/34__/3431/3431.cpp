#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    int sx;
    int ex;
    int idx;
};

int group[100010];

bool cmp(Line a, Line b) {
    return a.sx < b.sx;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<Line> lines;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lines.push_back({ a , b , i + 1 });
    }

    sort(lines.begin(), lines.end(), cmp);

    int gid = 1;
    int ed = lines[0].ex;
    for (int i = 0; i < n; i++) {
        if (lines[i].sx > ed) {
            // 안겹침
            gid++;
        }
       
        ed = max(ed, lines[i].ex);
        group[lines[i].idx] = gid;
    }

    while (q) {
        int a, b;
        cin >> a >> b;
        cout << (group[a] == group[b] ? "1" : "0") << "\n";
        q--;
    }
}
