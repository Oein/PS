#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    stack<int> st;
    cin >> n;
    while(n--){
        char x;
        cin >> x;
        if(x == 'i'){
            int g;
            cin >> g;
            st.push(g);
        }
        if(x == 'c'){
            cout << st.size() << "\n";
        }
        if(x == 'o'){
            if(st.empty()) cout << "empty\n";
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
    }
}