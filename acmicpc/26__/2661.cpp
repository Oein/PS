#include <iostream>
using namespace std;

int n;

bool isOk(string s){
    int sl = s.size();
    if(sl < 2) return true;
    
    for(int cds = 1; cds <= sl / 2;cds++){
        string rst = s.substr(sl - cds , cds);
        string lst = s.substr(sl - cds - cds , cds);
        if(lst == rst) return false;
    }
    
    return true;
}

void dfs(int dig , string s){
    if(dig == n){
        cout << s;
        exit(0);
    }
    
    for(int i = 1; i <= 3;i++){
        string xyy = to_string(i);
        string ns = s + xyy;
        if(!isOk(ns)) continue;
        
        dfs(dig + 1 , ns);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    dfs(1 , "1");
}
