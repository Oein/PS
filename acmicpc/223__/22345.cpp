#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> inputs[200010];

ll n, Q;
ll A[200010], B[200010], C[200010];

int main() {
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> inputs[i].second >> inputs[i].first;
    }
    sort(inputs + 1, inputs + n + 1);

    for (int i = 1; i <= n; i++) {
        A[i] = A[i - 1] + inputs[i].second;
        B[i] = B[i - 1] + inputs[i].second * inputs[i].first;
        C[i - 1] = inputs[i].first;
    }

    while (Q--) {
        int qq;
        cin >> qq;

        int qqq = lower_bound(C, C + n, qq) - C; // qq 위치 - 1

        cout << 2 * qq * A[qqq] - qq * A[n] + B[n] - 2 * B[qqq] << "\n";
    }
}