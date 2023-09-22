#include <iostream>
using namespace std;


int main()
{
    int N = 0;
    cin >> N;
    char name[150][30] = { 0, };
    int howmanyfisrtname[26] = { 0, };

    for (int i = 0; i < N; i++) {
        cin >> name[i];
    }

    for (int i = 0; name[i][0] != 0; i++) {
        howmanyfisrtname[((int)name[i][0]) - 97]++;
    }

    bool cango = false;

    for (int i = 0; i < 26; i++) {
        if (howmanyfisrtname[i] >= 5) {
            cout << ((char)(i + 97));
            cango = true;
        }
    }

    if (cango == false) cout << "PREDAJA";
}