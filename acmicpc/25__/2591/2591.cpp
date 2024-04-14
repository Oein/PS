#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int memo[45];
string s;

int solve(int i){
    if(s.size() <= i) return 0;
    if(memo[i] != -1) return memo[i];
    memo[i] = 0;
    if(s[i] - '0' == 0){
        return memo[i];
    }
    if(i == s.size() - 1) memo[i]++;
    else {
        if((s[i] - '0') * 10 + (s[i + 1] - '0') <= 34) {
            memo[i] += solve(i + 1);
            memo[i] += solve(i + 2);
            if(i == s.size() - 2) memo[i]++;
        }else {
            memo[i] += solve(i + 1);
        }
    }
    
    return memo[i];
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> s;
    for(int i = 0;i < s.size();i++){
        memo[i] = -1;
    }
    cout << solve(0);
}


