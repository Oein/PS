#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int n;
ll cow[80005];
ll ans;
stack<int> st;

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++) {
            cin >> cow[i];
            while(!st.empty() && st.top() <= cow[i]){
                st.pop();
            }
            ans += st.size();
            st.push(cow[i]);
    }
    cout << ans;
}
