// Example program
#include <iostream>

using namespace std;

int main()
{
    int h = 0, m = 0;
    cin >> h >> m;
    if (m - 45 < 0) {
        m += 60;
        if (h - 1 < 0) {
            h = 23;
            cout << h << " " << m - 45;
            return 0;
        }
        cout << h - 1 << " " << m - 45;
        return 0;
    }

    cout << h << " " << m - 45;
}
