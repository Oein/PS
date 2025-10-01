#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

/*
2^(n^2)

다른색 끼리는 영향이 없음
  -> 다른색은 볼 필요가 없음
  -> 개별적으로 계산 가능
  -> 판이 판 / 2 가됨..?
  */

int n;
// usedRTL[x + n - y - 1] = T | F
bool usedRTL[30];
// usedLTR[n - x - 1 + n - y - 1] = T | F
bool usedLTR[30];
// placeAbles[idx] = {y , x};
vector<pii> placeAbles;
vector<pii> placeAblesBl;

// R to L fomu :x + n - y - 1
// L to R fomu : n - x - 1 + n - y - 1

int placed = 0;
int maxPlaced[3] = {0 , 0};
int color = 0;
void dfs(int plidx){
    if(plidx == (color == 0 ? placeAbles :placeAblesBl).size()){
        maxPlaced[color] = max(maxPlaced[color] , placed);
        return;
    }

    if(maxPlaced[color] > (color == 0 ? placeAbles :placeAblesBl).size() - plidx + placed + 4) {
        return;
    }

    // 설치 안함
    dfs(plidx + 1);


    pii now = (color == 0 ? placeAbles :placeAblesBl)[plidx];
    // 설치
    if(
       !usedRTL[now.second + n - now.first - 1] &&
       !usedLTR[n - now.second - 1 + n - now.first - 1]
    ) {
        usedRTL[now.second + n - now.first - 1] = 1;
        usedLTR[n - now.second - 1 + n - now.first - 1] = 1;
        placed++;

        dfs(plidx + 1);

        usedRTL[now.second + n - now.first - 1] = 0;
        usedLTR[n - now.second - 1 + n - now.first - 1] = 0;
        placed--;
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            int x;
            cin >> x;
            if(x == 1) {
                if(((j % 2) + (i  % 2)) % 2 == 0){
                    placeAbles.push_back({i , j});
                }else{
                    placeAblesBl.push_back({i , j});
                }
            }
        }
    }

    dfs(0);
    color = 1;
    for(int i = 0;i < 30;i++) {
            usedRTL[i] = 0;
            usedLTR[i] = 0;
    }
    dfs(0);
    cout << maxPlaced[0] + maxPlaced[1];
}
