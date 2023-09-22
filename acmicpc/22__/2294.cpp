#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int lucaip[100010]; // lowest used coin at indexed price
int cp[110]; // coins's price

int mINT_MAX = 200000;

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) cin >> cp[i];

    for (int i = 1; i <= K; i++) lucaip[i] = mINT_MAX;

    for (int i = 1; i <= N; i++)
    {
        for (int j = cp[i]; j <= K; j++)
        {
            lucaip[j] = min(lucaip[j], lucaip[j - cp[i]] + 1);
        }
    }

    if (lucaip[K] == mINT_MAX) cout << -1 << endl;
    else cout << lucaip[K] << endl;
}
