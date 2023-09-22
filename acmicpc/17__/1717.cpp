#include <iostream>
using namespace std;

int parent[1000001];
int n;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void _union(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px > py) parent[px] = py;
    else if (px < py) parent[py] = px;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m;

    cin >> n >> m;

    for (int i = 0; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 0) {
            _union(x, y);
        } else {
            if (find(x) == find(y)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
