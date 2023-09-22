#include <iostream>
using namespace std;
int n,A[505];
int main() {
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> A[i];
    
    int ans = n - 2;
    int diff = 0;

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            diff = max(A[j]-A[i],A[i]-A[j]);
            if(diff % (j - i))continue;
            
            int cnt = 0;
            for(int t=1;t<=n;t++){
                if(A[i] + ((A[j] - A[i]) / (j - i)) * (t - i) == A[t])cnt++;
            }

            ans = min(ans,n - cnt);
        }
    }

    cout<<ans<<"\n";
}