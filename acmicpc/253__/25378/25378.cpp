#include <iostream>
#include <algorithm>
using namespace std;

int N, a[2503], DP[2503];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) {
        int tmp = a[i];
        DP[i] = max(DP[i], DP[i - 1]);
        for (int j = i + 1; j < N; j++) {
            tmp = a[j] - tmp;
            if (tmp < 0) break;
            else if (tmp == 0) DP[j] = DP[i - 1] + 1;
        }
    }
    cout << N - DP[N - 1];
}