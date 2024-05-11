#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include <limits>
#include <string>
#include <cmath>
#include <stack>
#include <climits>
#include <queue>
using namespace std;
using ll = long long;

struct Gem {
    int weight;
    int price;
};

vector<Gem> gems;
vector<int> bags;

int dp[1005][10005] = {0,};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        int p, w;
        cin >> w >> p;
        gems.push_back({w,p});
    }
    for(int i = 0;i < k;i++) {
        int b;
        cin >> b;
        bags.push_back(b);
    }
    
    sort(gems.begin(), gems.end(), [](Gem a, Gem b) {
        return a.weight < b.weight;
    });
    sort(bags.begin(), bags.end());
    
    long long ans = 0;
    
    priority_queue<int> pq;
    int access = 0;
    for(int i = 0;i < k;i++) {
        while (access < n && gems[access].weight <= bags[i]) {
            pq.push(gems[access].price);
            access++;
        }
        
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    
    cout << ans;
}
