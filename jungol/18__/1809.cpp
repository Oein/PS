#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int n;
stack<pii> st;

int outs[500005];

int rasers[500005];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> rasers[i];

    for(int i = n;i >= 1; i--) {
        int nowHei = rasers[i];
        while(!st.empty() && st.top().first < nowHei) {
            outs[st.top().second] = i;
            st.pop();
        }

        st.push({nowHei , i});
    }

    while(!st.empty()){
        outs[st.top().second] = 0;
        st.pop();
    }

    for(int i = 1;i <= n;i++) cout << outs[i] << " ";
}
