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

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

int board[515][515];
int n;

/*
 1
 0 1
 1 1

 2
 2 0
 2 2

 3
 3 3
 0 3

 4
 4 4
 4 0
*/

enum BS{
    LT = 1,
    RT = 2,
    LB = 3,
    RB = 4,
    EMPTY = 0
};

struct x{
    int first;
    int second;
};

x set_[5][3] = {
    {
        {-1,-1},{-1,-1},{-1,-1}
    },
    {
                {1 , 0},
        {0 , 1},{1 , 1},
    },
    {
        {0 , 0},
        {0 , 1}, {1 , 1},
    },
    {
        {0 , 0},{1 , 0},
                {1 , 1},
    },
    {
        {0 , 0},{1 , 0},
        {0 , 1},
    },
};

BS wie(int sz , int sx , int sy , int ex , int ey) {
    int midX = sx + sz / 2;
    int midY = sy + sz / 2;
    if(ex < midX) {
        if(ey < midY) {
            return BS::LT;
        }else{
            return BS::LB;
        }
    }else {
        if(ey < midY) {
            return BS::RT;
        }else{
            return BS::RB;
        }
    }
}

void printBoard() {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "------------\n\n";
}

void solve(int sz , int sx , int sy , int ex , int ey) {
    int sd = sz / 2;
    int w = wie(sz , sx , sy , ex , ey);
    if(sz == 2) {
        for(int i = 0;i < 3;i++) {
            board[set_[w][i].second + sy][set_[w][i].first + sx] = w;
        }
        // printBoard();
        return;
    }

    int midX = sx + sd - 1;
    int midY = sy + sd - 1;
    for(int i = 0;i < 3;i++) {
        board[set_[w][i].second + midY][set_[w][i].first + midX] = w;
    }

    // printBoard();

    // LT
    if(w == BS::LT) {
        solve(sd , sx , sy , ex , ey);
    }else {
        solve(sd , sx , sy , midX , midY);
    }

    // RT
    if(w == BS::RT) {
        solve(sd , sx + sd , sy , ex , ey);
    } else {
        solve(sd , sx + sd , sy , midX + 1 , midY);
    }

    // LB
    if(w == BS::LB) {
        solve(sd , sx , sy + sd , ex , ey);
    } else {
        solve(sd , sx , sy + sd , midX , midY + 1);
    }

    // RB
    if(w == BS::RB) {
        solve(sd , sx + sd , sy + sd , ex , ey);
    } else {
        solve(sd , sx + sd , sy + sd , midX + 1 , midY + 1);
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    int ex , ey;
    cin >> n >> ey >> ex;
    solve(n , 0 , 0 , ex , ey);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}