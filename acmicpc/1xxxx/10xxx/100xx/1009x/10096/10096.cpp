#include <iostream>
using namespace std;

bool prnt = false;

string str;

bool check(int s, int e, int s2)
{
    bool passed = false;

    // right is right
    for (int i = s, j = s2; i < e; i++ , j++) {
        if (str[i] == str[j]) continue;

        // 다름
        if (passed) return false;
        passed = true;
        i--;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    
    cin >> n >> str;
    if (n % 2 == 0) {
        cout << "NOT POSSIBLE";
        return 0;
    }

    int mid = n / 2;

    bool cl = check(0, mid, mid);
    bool cr = check(mid + 1, n, 0);

    if (cl && cr) {
        if (str.substr(0, mid) == str.substr(mid + 1, mid)) {
            cout << str.substr(0, mid);
            return 0;
        }
        cout << "NOT UNIQUE";
        return 0;
    }

    if (!cl && !cr) {
        cout << "NOT POSSIBLE";
        return 0;
    }

    if (cl) {
        cout << str.substr(0, mid);
        return 0;
    }
    cout << str.substr(mid + 1, mid);
}