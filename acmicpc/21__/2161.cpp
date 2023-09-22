#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    deque<int> q;
    for(auto i=1; i<=n; i++){
        q.push_back(i);
    }
    bool should_delete = true;
    while (!q.empty()){
        int top = q.front();
        q.pop_front();
        if (should_delete){
            should_delete = false;
            cout << top << ' ';
        }else {
            should_delete = true;
            q.push_back(top);
        }
    }
}
