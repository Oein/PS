#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pii;

int n;
stack<pii> st;
ll heights[100005];
ll leftHei[100005];
ll rightHei[100005];
ll ans = 0;

/**
    높이에 따라 왼쪽 오른쪽 point를 구하고 계산
**/

int main(){
    int n;
    cin >> n;
    ll maxSi = 0;
    for(int i = 0;i < n;i++) cin >> heights[i];

    // get Left
    for(int i = 0;i < n;i++){
        while(!st.empty() && st.top().first >= heights[i]) st.pop();
        leftHei[i] = (st.empty() ? -1 : st.top().second);
        st.push({heights[i] , i});
    }

    while(!st.empty()) st.pop();

    // get Right
    for(int i = n - 1;i >= 0;i--){
        while(!st.empty() && st.top().first >= heights[i]) st.pop();
        rightHei[i] = (st.empty() ? n : st.top().second);
        st.push({heights[i] , i});
    }

    // get All sizes
    for(int i = 0;i < n;i++){
        ans = max(ans ,
                heights[i] * (rightHei[i] - leftHei[i] - 1)
            );
    }
    cout << ans;
}
