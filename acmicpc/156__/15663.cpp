#include <bits/stdc++.h>

using namespace std;

vector<int> values;
set<string> is_printed;
int n, m;

void solve(vector<int>& data) {
    if (data.size() == m) {
        //print

        string out_data = "";

        for (int i = 0; i < data.size(); i++) {
            out_data += to_string(values[data[i]]) + " ";
        }
        out_data += "\n";

        if (is_printed.find(out_data) == is_printed.end()) {
            cout << out_data;
            is_printed.insert(out_data);
        }

        return;
    }

    for (int i = 0; i < n; i++) {
        bool ok = true;

        for (int j = 0; j < data.size(); j++) {
            if (i == data[j]) {
                ok = false;
                break;
            }
        }
        if (ok == false) continue;

        data.push_back(i);
        solve(data);
        data.pop_back();
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

    vector<int> d;
    solve(d);
}