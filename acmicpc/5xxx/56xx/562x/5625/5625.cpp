#include <iostream>
using namespace std;

int counts[2][1000001];

class Triangle {
public:
    int low_x = 123456789;
    int high_x = -123546789;
    int low_y = 123456789;
    int high_y = -123456789;

    void insert(int new_x, int new_y) {
        if (new_x < this->low_x) this->low_x = new_x;
        if (new_x > this->high_x) this->high_x = new_x;
        if (new_y < this->low_y) this->low_y = new_y;
        if (new_y > this->high_y) this->high_y = new_y;
    }

    bool inside_x(int pos) {
        if (pos > this->low_x && pos < this->high_x) return true;
        return false;
    }

    bool inside_y(int pos) {
        if (pos > this->low_y && pos < this->high_y) return true;
        return false;
    }

    void print_self() {
        cout << "x : " << this->low_x << " ~ " << this->high_x << "  y : " << this->low_y << " ~ " << this->high_y << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tree_count = 0;
    cin >> tree_count;
    int high_x = -123456789;
    int high_y = -123456789;

    for (int i = 0; i < tree_count; i++) {
        Triangle tri;

        int x2 = 0;
        int y2 = 0;
        int x3 = 0;
        int y3 = 0;

        cin >> tri.high_x >> tri.high_y >> x2 >> y2 >> x3 >> y3;

        tri.low_x = tri.high_x;
        tri.low_y = tri.high_y;

        tri.insert(x2, y2);
        tri.insert(x3, y3);

        counts[0][tri.low_x + 1]++;
        counts[0][tri.high_x]--;
        counts[1][tri.low_y + 1]++;
        counts[1][tri.high_y]--;
        if (tri.high_x > high_x) high_x = tri.high_x;
        if (tri.high_y > high_y) high_y = tri.high_y;
    }

    int add = 0;
    for (int i = 0; i <= high_x; i++) {
        counts[0][i] += add;
        add = counts[0][i];
    }

    add = 0;
    for (int i = 0; i <= high_y; i++) {
        counts[1][i] += add;
        add = counts[1][i];
    }

    int cmd_count = 0;
    cin >> cmd_count;
    char equal = 'e';
    for (int i = 0; i < cmd_count; i++) {
        char x_y = '0';
        int pos = 0;
        cin >> x_y >> equal >> pos;

        cout << counts[x_y == 'x' ? 0 : 1][pos] << "\n";
    }
}