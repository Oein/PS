#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int n;
stack<pii> st;

int outs[100005];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        int nowHei = 0;
        cin >> nowHei;
        while(!st.empty() && st.top().first < nowHei){
            outs[st.top().second] = i + 1;
            st.pop();
        }
        st.push({nowHei , i});
    }

    while(!st.empty()){
        outs[st.top().second] = 0;
        st.pop();
    }

    for(int i = 0;i < n;i++) cout << outs[i] << "\n";
}
