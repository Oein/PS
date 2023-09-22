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

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

int main(){
    cin.tie(0); cout.tie(0);
    priority_queue<int> minq , maxq;
    int n , mid;
    cin >> n >> mid;
    cout << mid << "\n";
    for(int i = 0;i < n / 2;i++) {
        int a , b;
        cin >> a >> b;
        if(a < mid) maxq.push(a);
        else minq.push(-a);

        if(b < mid) maxq.push(b);
        else minq.push(-b);

        if(maxq.size() < minq.size()) {
            maxq.push(mid);
            mid = -minq.top();
            minq.pop();
        }else if(maxq.size() > minq.size()) {
            minq.push(-mid);
            mid = maxq.top();
            maxq.pop();
        }

        cout << mid << "\n";
    }
}