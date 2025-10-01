#include <iostream>

using namespace std;

int main()
{
    int amu[32]; // a multiply
    int bmu[32]; // b multiply

    int d;
    int k;
    cin >> d >> k;

    amu[1] = 1;
    amu[2] = 0;
    bmu[1] = 0;
    bmu[2] = 1;

    for (int i = 3; i <= d; i++) {
        amu[i] = amu[i - 1] + amu[i - 2];
        bmu[i] = bmu[i - 1] + bmu[i - 2];
    }

    for (int i = 1; i <= k; i++) {
        if ((k - amu[d] * i) % bmu[d] == 0) {
            cout << i << "\n" << (k - amu[d] * i) / bmu[d];
            break;
        }
    }
}