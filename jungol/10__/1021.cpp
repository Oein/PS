#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define sout if(false) cout << space(stack)

// map<x,j> recipe[i] = i를 만들기 위해 x가 j개 필요하다
map<int, int> recipe[105];
map<int, int> dp[105];

bool isNotDefaultModule[105];
bool calculated[105];

void addi(int to, int key, int val) {
    if(dp[to].find(key) == dp[to].end()) dp[to][key] = 0;
    dp[to][key] += val;
}

string space(int cnt) {
    string out = "";
    while(cnt--) out += " ";
    return out;
}

int stack = 0;

void requestSub(int me) {
    if(calculated[me]) return;
    if(!isNotDefaultModule[me]) {
        dp[me][me] = 1;
        calculated[me] = true;
        return;
    }
    stack++;
    
    sout << "Calculate " << me << "\n";
    for(auto submodule: recipe[me]) {
        // sub module을 만드는 기본모듈을 요청
        requestSub(submodule.first);
        for(auto submodules_sub : dp[submodule.first]) {
            sout << "It needs " << submodules_sub.first << " x " << submodules_sub.second * submodule.second << "\n";
            addi(me, submodules_sub.first, submodules_sub.second * submodule.second);
        }
    }
    calculated[me] = 1;
    
    stack--;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    while (m --) {
        int toMake; // X
        int need;   // Y
        int many;   // K
        
        cin >> toMake >> need >> many;
        isNotDefaultModule[toMake] = true;
        recipe[toMake][need] = many;
    }
    
    requestSub(n);
    
    for(auto x : dp[n]) {
        cout << x.first << " " << x.second << "\n";
    }
}
