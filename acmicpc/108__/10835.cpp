#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct State {
    vector<int> ac;
    vector<int> bc;
    int sc = 0;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int coc = 0; // count of card
    State ds; // defualt state

    cin >> coc;

    for (int i = 0; i < coc; i++) {
        int t;
        cin >> t;
        ds.ac.push_back(t);
    }

    for (int i = 0; i < coc; i++) {
        int t;
        cin >> t;
        ds.bc.push_back(t);
    }

    reverse(ds.ac.begin(), ds.ac.end());
    reverse(ds.bc.begin(), ds.bc.end());

    queue<State> q;
    q.push(ds);

    int ans = 0;

    while (!q.empty()) {
        State now = q.front();

        if (now.bc.size() == 0 || now.ac.size() == 0) {
            ans = max(ans, now.sc);
            q.pop();
            continue;
        }

        int al = now.ac.back();
        int bl = now.bc.back();

        // 다 버리기
        // cout << "OK before all\n";
        now.ac.pop_back();
        now.bc.pop_back();
        q.push(now);
        now.ac.push_back(al);
        now.bc.push_back(bl);

        //왼쪽 버리기
        // cout << "OK before left\n";
        now.ac.pop_back();
        q.push(now);
        now.ac.push_back(al);

        //오른쪽 버리기
        // cout << "OK before right\n";
        if (now.bc.back() < now.ac.back()) {
            now.sc += now.bc.back();
            now.bc.pop_back();
            q.push(now);
        }

        q.pop();
    }

    cout << ans;
}
