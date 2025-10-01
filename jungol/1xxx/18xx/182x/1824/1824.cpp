#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pii;

// board[y][x] = dt
int board[10][10];
bool usedX[12][12];
bool usedY[12][12];
bool usedRec[5][5][12];

// emptys[idx] = {y , x};
vector<pii> emptys;

bool able(int y , int x , int dt){
    return (
        usedX[y][dt] == false &&
        usedY[x][dt] == false &&
        usedRec[y / 3][x / 3][dt] == false
    );
}

void doIt(int empIdx){
    if(empIdx == emptys.size()){
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    for(int i = 1;i <= 9;i++){
        if(able(emptys[empIdx].first , emptys[empIdx].second , i)){
            usedX[emptys[empIdx].first][i] = true;
            usedY[emptys[empIdx].second][i] = true;
            usedRec[emptys[empIdx].first / 3][emptys[empIdx].second / 3][i] = true;
            board[emptys[empIdx].first][emptys[empIdx].second] = i;

            doIt(empIdx + 1);

            usedX[emptys[empIdx].first][i] = false;
            usedY[emptys[empIdx].second][i] = false;
            usedRec[emptys[empIdx].first / 3][emptys[empIdx].second / 3][i] = false;   
            board[emptys[empIdx].first][emptys[empIdx].second] = 0;
        }
    }
}

int main(){
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            cin >> board[i][j];
            if(board[i][j] == 0) {
                emptys.push_back({i , j});
            }else{
                usedX[i][board[i][j]] = true;
                usedY[j][board[i][j]] = true;
                usedRec[i / 3][j / 3][board[i][j]] = true;
            }
        }
    }

    doIt(0);
}
