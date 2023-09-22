#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pii;

int n;

bool isOk(string num){
    int numSize = num.size();
    if(numSize < 2) return 1;
    for(int i = 1;i <= numSize / 2;i++){
        //                           두번 왼쪽 에서     i개
        string leftStr = num.substr(numSize - i - i , i);
        string rightStr = num.substr(numSize - i , i);
        if(leftStr == rightStr) return 0;
    }
    return 1;
}

// ull 써도 너무 커서 string
void dfs(int digi , string num){
    if(digi == n){
        cout << num;
        exit(0);
    }

    for(int i = 1;i <= 3;i++){
        string ist = to_string(i);
        string newStr = num + ist;
        if(!isOk(num)) continue;

        dfs(digi + 1 , newStr);
    }
}

int main(){
    cin >> n;
    dfs(1 , "1");
    dfs(1 , "2");
    dfs(1 , "3");
}
