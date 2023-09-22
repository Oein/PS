#include <bits/stdc++.h>

using namespace std;

int main() {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) return 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        stack<int> s;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && v[s.top()] > v[i]) {
                long long height = v[s.top()];
                s.pop();
                int width = i;
                if (!s.empty()) width = i - s.top() - 1;
                if (ans < width * height) ans = width * height;
            }
            s.push(i);
        }
        while (!s.empty()) {
            long long height = v[s.top()];
            s.pop();
            int width = n;
            if (!s.empty()) width = n - s.top() - 1;
            if (ans < width * height) ans = width * height;
        }
        cout << ans << "\n";
    }
}