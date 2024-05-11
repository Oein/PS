#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

ll arr[1505];

int main(){
    cin.tie(0); cout.tie(0);
    priority_queue<ll , vector<ll> , greater<ll> > pq;

    pq.push(1);
    int ah = 1;

    set<ll> ins;

    while(ins.size() < 1500) {
        // cout << "PT : " << pq.top() << "\n";
        
        if(ins.find(pq.top()) != ins.end()) {
            pq.pop();
            continue;
        }
        ins.insert(pq.top());
        arr[ah] = pq.top();
        // cout << ah << " : " << pq.top() << endl;
        ah++;
        
        if(ins.find(pq.top() * 2) == ins.end()) pq.push(pq.top() * 2);
        if(ins.find(pq.top() * 3) == ins.end()) pq.push(pq.top() * 3);
        if(ins.find(pq.top() * 5) == ins.end()) pq.push(pq.top() * 5);
        pq.pop();
    }

    int x;
    cin >> x;
    while(x != 0) {
        cout << arr[x] << "\n";
        cin >> x;
    }
}
