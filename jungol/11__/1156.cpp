#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
int n, k, arr[100005];
ll low, high, ans = 0;
bool able(ll dt) {
    int groupCnt = 1;
    ll work = 0;
    for(int i = 0;i < n;i++)
        if(work + arr[i] > dt) {
            groupCnt++;
            work = arr[i];
        } else work += arr[i];
    
    return groupCnt <= k;
}

void output(int idx, ll sum, int ck) {
    if (idx < 0) return;
    if (sum + arr[idx] > low || idx < ck) {
        output(idx - 1, arr[idx], ck - 1);
        cout << arr[idx] << " / ";
    }
    else {
        output(idx - 1, sum + arr[idx], ck);
        cout << arr[idx] << " ";
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0;i < n;++i) {
        cin >> (arr[i]);
        if(low < arr[i]) low = arr[i];
        high += arr[i];
    }
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        if(able(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    output(n - 1, 0, k - 1);
}
