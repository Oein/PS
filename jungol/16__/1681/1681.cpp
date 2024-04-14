#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pii;
// global varable
int n;
// cost[from][to] = COST
int cost[15][15];
// for go function
bool visited[15];
int nowCost = 0;
int leftSpot = 0;
int minCost = 2100000000;

void go(int where){
    if(leftSpot == 0){
        if(cost[where][0] <= 0) return;
        minCost = min(minCost , nowCost + cost[where][0]);
        return;
    }

    for(int i = 0;i < n;i++){
        if(visited[i]) continue;
        if(cost[where][i] <= 0) continue;
        if(nowCost + cost[where][i] > minCost) continue;

        leftSpot--;
        nowCost += cost[where][i];
        visited[i] = true;
        go(i);
        visited[i] = false;
        nowCost -= cost[where][i];
        leftSpot++;
    }
}

int main(){
    cin >> n;
    leftSpot = n - 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> cost[i][j];
        }
    }

    visited[0] = true;
    go(0);
    cout << minCost;
}
