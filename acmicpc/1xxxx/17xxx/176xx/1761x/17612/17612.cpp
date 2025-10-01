#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <numbers>
#include <cassert>
#include <limits.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

int n , k;

struct Customer {
    int id , w , gaeSanDaeIdx , processEndTime;

    bool operator<(const Customer& c) const {
        if(this->processEndTime == c.processEndTime) return this->gaeSanDaeIdx > c.gaeSanDaeIdx;
        return this->processEndTime < c.processEndTime;
    }
};

struct Processer {
    int idx;
    unsigned long long nt = 0;

    bool operator<(const Processer& a) const {
        if(this->nt == a.nt) return this->idx > a.idx;
        return this->nt > a.nt;
    }
};

vector<Customer> cuts;
priority_queue<Processer> pq;
unsigned long long ans = 0;

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n >> k;

    for(int i = 0;i < k;i++) {
        pq.push({i , 0});
    }

    for(int i = 0;i < n;i++) {
        Customer x;
        cin >> x.id >> x.w;
        Processer y = pq.top();
        y.nt += x.w;
        x.gaeSanDaeIdx = y.idx;
        x.processEndTime = y.nt;

        pq.pop();
        pq.push(y);
        cuts.push_back(x);
    }

    sort(cuts.begin(), cuts.end());

    int nowOn = 1;
    for(auto x : cuts) {
        ans += (unsigned long long)x.id * (unsigned long long)nowOn;
        nowOn++;
    }

    cout << ans;
}