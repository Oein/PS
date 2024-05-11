#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int parent_union[200020];
int level_union[200020];
int parant[200020];
int n;

int query[400010][3];

//                union found
int union_find(int u){
    if(u == parent_union[u]) return u;
    return parent_union[u] = union_find(parent_union[u]);
}

void union_merge(int u, int v){
    u = union_find(u);
    v = union_find(v);

    if(u == v) return;
    if(level_union[u] > level_union[v]) swap(u, v);
    parent_union[u] = v;
    if(level_union[u] == level_union[v]) level_union[v]++;
}
// -------------------------------------------------

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0; i<=200000; i++){
        parent_union[i] = i;
        level_union[i] = 1;
    }
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    parant[1] = 1;
    for(int i = 2; i <= n; i++){
        int t;
        cin >> t;
        parant[i] = t;
    }
    
    q += (n-1);
    
    for(int i=0; i < q; i++){
        int op;
        cin >> op;
        if(op) cin >> query[i][1] >> query[i][2]; // if it is case 2
        else{ // or it is 1
            cin >> query[i][1];
            query[i][2] = 0;
        }
    }
    
    stack<bool> s;
    for(int i=q-1; i>=0; i--){ // 끊기 x , 연결 o 이니가 반대로 해야됨
        if(query[i][2]){
            if(union_find(query[i][1]) == union_find(query[i][2])) s.push(true); // 끝어지지 않음 , root가 같음
            else s.push(false);
        }else{
            union_merge(query[i][1], parant[query[i][1]]);
        }
    }


    while(!s.empty()){ // 반대로 했으니까 출력도 반대로
        cout << (s.top()?"YES":"NO") << "\n"; s.pop();
    }

    return 0;
}
