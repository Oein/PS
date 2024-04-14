#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

struct Blood {
    string name;
    int age;
    double blooding;
};
struct BloodComp {
    bool operator()(const Blood& a, const Blood& b) const {
        if(a.blooding == b.blooding) return a.age < b.age;
        return a.blooding < b.blooding;
    }
};
int main() {
    int q;
    priority_queue<Blood, vector<Blood>, BloodComp> pq;
    cin >> q;
    while(q--) {
        string cmd;
        cin >> cmd;
        if(cmd == "pop") {
            if(pq.empty()) continue;
            Blood b = pq.top();
            pq.pop();
            cout << b.name << "\n";
        } else {
            Blood b;
            cin >> b.name >> b.age >> b.blooding;
            pq.push(b);
        }
    }
}
