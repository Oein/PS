#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;

string str, ables;
int ans = 0;
bool used[15];

void dfs(int step) {
    if(step == ables.size()) {
        ans++;
        return;
    }
    
    for(int i = 0;i < ables.size();i++) {
        if(used[i]) continue;
        if(step > 0 && str[step - 1] == ables[i]) continue;
        
        used[i] = 1;
        str[step] = ables[i];
        dfs(step + 1);
        used[i] = 0;
    }
}

int fibo(int n) {
    int x = 1;
    for(int i = 2; i <= n; i++) x *= i;
    return x;
}

int main() {
    cin >> ables;
    str = ables;
    
    bool allables = 1;
    int g[30] = {0,};
    
    for(int i = 0;i < ables.size();i++) {
        if(g[ables[i] - 'a']) {
            allables = 0;
        }
        
        g[ables[i] - 'a']+=1;
    }
    
    if(allables) {
        cout << fibo(ables.size());
        return 0;
    }
    
    dfs(0);
    
    int divider = 1;
    
    for(int i = 'a';i <= 'z';i++) divider *= fibo(g[i - 'a']);
    
    cout << ans / divider;
}
