#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

const int NOTHING = 0;
const int ALLWHIT = 1;
const int ALLBLUE = 2;
const int WHITEPA = 0;
const int BLUEPAI = 1;

int n;
// board[y][x]
int board[1030][1030];

int ansWhite = 0;
int ansBlue = 0;

int allSomeThing(int stX , int stY , int edX , int edY){
    bool allWhite = true;
    bool allBlue = true;
    for(int i = stY;i <= edY;i++){
        for(int j = stX;j <= edX;j++){
            if(board[i][j] == WHITEPA) allBlue = false;
            if(board[i][j] == BLUEPAI) allWhite = false;
        }
    }

    if(allWhite) return ALLWHIT;
    if(allBlue) return ALLBLUE;
    return NOTHING;

}

void split(int stX , int stY , int edX , int edY){
    if(stX == edX && stY == edY){
        //cout << "One Block " << stX << " , " << stY << "\n";
        if(board[stY][stX] == WHITEPA) ansWhite++;
        else ansBlue++;

        cout << board[stY][stX];
        return;
    }

    int as = allSomeThing(stX , stY , edX , edY);
    if(as > 0){
        //cout << "Complete " << stX << " , " << stY << "  ~  " << edX <<" , " << edY << " : " << (as == ALLWHIT ? "W" : "B") << "\n";
        if(as == ALLWHIT) ansWhite++;
        if(as == ALLBLUE) ansBlue++;
        cout << ((as == ALLWHIT) ? 0 : 1);
        return;
    }else{
        cout << "X";
    }

    int midX = (stX + edX) / 2;
    int midY = (stY + edY) / 2;

    split(stX , stY , midX , midY); // left top
    split(midX + 1 , stY , edX , midY); // right top
    split(stX , midY + 1 , midX , edY); // left bottom
    split(midX + 1 , midY + 1 , edX , edY); // right bottom
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> board[i][j];
        }
    }

    split(0 , 0 , n - 1 , n - 1);
}
