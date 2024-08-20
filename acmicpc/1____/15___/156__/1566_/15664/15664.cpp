#include "bits/stdc++.h"

using namespace std;

vector<int> values;
set<string> is_printed;
int n, m;
vector<int> now;

void solve() {
    if (now.size() == m) {
        //print

        string out_data = "";

        for (int i = 0; i < now.size(); i++) {
            out_data += to_string(values[now[i]]) + " ";
        }
        out_data += "\n";

        if (is_printed.find(out_data) == is_printed.end()) {
            cout << out_data;
            is_printed.insert(out_data);
        }

        return;
    }

    for (int i = now.size() == 0 ? 0 : now.back() + 1; i < n; i++) {
        now.push_back(i);
        solve();
        now.pop_back();
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        values.push_back(temp);
    }

    sort(values.begin(), values.end());


    solve();
}