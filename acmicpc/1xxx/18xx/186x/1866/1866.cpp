#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 3005

int dp[MAX_N];
int location[MAX_N];
int sum[MAX_N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n = 0;
    int truckCost = 0;
    int helicopterCost = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> location[i];
    }

    sort(location + 1, location + n + 1);

    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + location[i];
    }

    cin >> truckCost >> helicopterCost;
    for(int i = 1;i <= n;i++){
        dp[i] = dp[i - 1] + truckCost * location[i];

        for(int j = i;j >= 1;j--){
            int mid = (i + j) / 2; // i ~ j 까지 heli + truck

            int leftCost = (location[mid] * ( mid - j + 1 ) - (sum[mid] - sum[j-1])) * truckCost;
			int rightCost = ((sum[i] - sum[mid-1]) - (location[mid] * ( i - mid + 1 ))) * truckCost;

			dp[i] = min(dp[i], dp[j-1] + leftCost + rightCost + helicopterCost);
        }
    }

    cout << dp[n];
}