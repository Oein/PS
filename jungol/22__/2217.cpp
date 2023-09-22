#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int n , ans = 987654321;
string arr[10];
bool used[10];

int moreLen(int aidx , int bidx){
    int aSize = arr[aidx].size(),
        bSize = arr[bidx].size();

    for (int sameCount = min(aSize, bSize); sameCount > 0; sameCount--) {
        int left , right;
        for (left = aSize - sameCount,
             right = 0;

             left < aSize;

             left++,
             right++
        ){
            if (arr[aidx][left] != arr[bidx][right]) break;
        }

        if (left == aSize) return bSize - sameCount;
    }
    return bSize;
}

void dfs(int uc , int ni , int len) {
    if(len > ans) return;
    if(uc >= n){
        ans = min(ans , len);
        return;
    }

    for(int i = 1;i <= n;i++){
        if(used[i]) continue;
        used[i] = 1;
        dfs(uc + 1 , i , len + moreLen(ni , i));
        used[i] = 0;
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    dfs(0 , 0 , 0);
    cout << ans;
}
