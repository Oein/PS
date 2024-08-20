#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <numbers>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;
typedef vector<int> vi;

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

// games[Country][Win | Same | Lose]
int games[10][5];
int result_games[10][5];
int team1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int team2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };

int ans = 0;

void dfs(int step) {
    if(step == 15) {
        if(ans != 1) {
            for(int i = 0;i < 6;i++) {
                for(int j = 0;j < 3;j++) {
                    if(result_games[i][j] != games[i][j]) return;
                }
            }
            ans = 1;
        }
        return;
    }

    int t1 = team1[step];
    int t2 = team2[step];

    result_games[t1][0]++; // W
    result_games[t2][2]++; // L
    dfs(step + 1);
    result_games[t1][0]--; // W
    result_games[t2][2]--; // L

    result_games[t1][1]++; // S
    result_games[t2][1]++; // S
    dfs(step + 1);
    result_games[t1][1]--; // S
    result_games[t2][1]--; // S

    result_games[t1][2]++; // L
    result_games[t2][0]++; // W
    dfs(step + 1);
    result_games[t1][2]--; // L
    result_games[t2][0]--; // W
}

void rmain() {
    ans = 0;
    
    for(int i = 0;i < 6;i++) {
        for(int j = 0; j< 3;j++) {
            result_games[i][j] = 0;
            cin >> games[i][j];
        }
    }

    dfs(0);

    cout << ans << " ";
}

int main(){
    cin.tie(0); cout.tie(0);
    for(int i = 0;i < 4;i++) {
        rmain();
    }
}