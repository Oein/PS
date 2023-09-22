#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<pair<int , int> , pair<int , int>> ppiipii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> msi;
typedef map<string , string> mss;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;
#define loopO(x, n) for(int x=1;x<=n;x++)
#define loopZ(x, n) for(int x=0;x<n;x++)

int n;
ll sum[100002] , a[100002];

ll func(int sti , int edi){
    if (sti == edi) return a[sti] * a[sti];
    int mid = (sti + edi) / 2;
    
    ll ret = max(func(sti, mid), func(mid + 1, edi));
    
    int low_l = mid;
    int high_r = mid + 1;
    ll min_D = min(a[low_l], a[high_r]);
    ret = max(ret, ( sum[high_r] - sum[low_l-1] ) * min_D);

    while (sti < low_l || high_r < edi) { // 넘어가면 안됨
       if (high_r < edi && ( sti == low_l || a[low_l - 1] < a[high_r + 1])) { // r이 최대가 아님 && (왼쪽이 최소값 || 오른쪽이 더 큰거)
           high_r += 1;
           min_D = min(min_D, a[high_r]);
       }
       else {
           low_l -= 1;
           min_D = min(min_D, a[low_l]);
       }
       ret = max(ret, (sum[high_r] - sum[low_l - 1]) * min_D);
    }
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    loopO(i, n){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    
    cout << func(1 , n);
}