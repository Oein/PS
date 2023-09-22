#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define ull unsigned long long
int dist[100005];
int distSum[100005];
ull dp[100005];
int oilPrice[100005];
int n;
int distByIndex(int a, int b) {
    if(a > b) swap(a, b);
    return distSum[b] - distSum[a];
}
int main() {
    cin >> n;
    for(int i = 0;i < n - 1;i++) cin >> dist[i];
    for(int i = 0;i < n;i++) {
        cin >> oilPrice[i];
        dp[i] = ULLONG_MAX;
        distSum[i + 1] = distSum[i] + dist[i];
    }
    
    // 끝 지점에서는 필요 없음
    dp[n - 1] = 0;
    
    for(int i = n - 2; i >= 0;i--) {
        // loop in all
        for(int j = i + 1; j < n; j++) {
            // i 에서 j 까지 사용될 연료를 지금 구매.
            int dist_ = distByIndex(i,j);
            ull price = oilPrice[i] * dist_;
            dp[i] = min(dp[i], price + dp[j]);
        }
    }
    
    cout << dp[0];
}
