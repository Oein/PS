#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int boardSize, netLen, fishCount;

struct Pos {
    int x;
    int y;
};

vector<Pos> fishes;

int getFishCnt(int sx, int sy, int lenx, int leny) {
    int ans = 0;
    for(auto fish : fishes) {
        if(fish.x < sx) continue;
        if(fish.x > sx + lenx) continue;
        if(fish.y < sy) continue;
        if(fish.y > sy + leny) continue;
        ans++;
    }
    return ans;
}

int main() {
    cin >> boardSize >> netLen >> fishCount;
    for(int i = 0;i < fishCount;i++) {
        int x,y;
        cin >> y >> x;
        fishes.push_back({x,y});
    }
    
    int ans = 0;
    
    for(auto fishA : fishes)
        for(auto fishB : fishes)
            for(int len = 1; len < netLen / 2; len++)
                ans = max(ans, getFishCnt(fishA.x, fishB.y, len, (netLen / 2) - len));
                
    
    cout << ans;
}
