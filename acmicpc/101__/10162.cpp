#include <iostream>
using namespace std;

int main() {
    int T, cntA = 0, cntB = 0, cntC = 0;
    cin >> T;

    cntA = T / 300;
    T %= 300;

    cntB = T / 60;
    T %= 60;

    cntC = T / 10;
    T %= 10;

    if (T != 0)
        cout << -1 << endl;
    else
        cout << cntA << " " << cntB << " " << cntC << endl;

    return 0;
}
