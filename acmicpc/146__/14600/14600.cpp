#include <iostream>
#include <math.h>
using namespace std;

bool prnt = false;

int board[6][6] = {0,};
int stairNum = 1;

int getWhereIs(int fpix , int fpiy , int x , int y , int siz){
    if(fpix >= x + siz / 2){ // right
        if(fpiy >= y + siz / 2){ // up
            return 1;
        }else{ // down
            return 4;
        }
    }else{ // left
        if(fpiy >= y + siz / 2){ // up
            return 2;
        }else{ // down
            return 3;
        }
    }
    
    return -1;
}

void dfs(int x , int y , int siz , int emx , int emy){
    int rfbm = getWhereIs(emx, emy, x, y, siz);
    if(prnt) cout << "Called " << x << " , " << y << " , " << siz << " , " << emx << " , " << emy << "\n";
    
    if(siz == 2){ // 최소 크기
        for(int i = 1; i <= 4;i++){
            int nemx = x + siz / 2 - ((i == 2 || i == 3) ? 1 : 0);
            int nemy = y + siz / 2 - ((i == 3 || i == 4) ? 1 : 0);
            
            if(prnt) cout << "Fill " << nemx << " , " << nemy << " : " << i << " , " << rfbm << "\n";
            if(i != rfbm){
                board[nemx][nemy] = stairNum;
            }
        }
        
        stairNum++;
        
        return;
    }
    
    int nst = stairNum;
    stairNum++;
    for(int i = 1; i <= 4;i++){
        int nx = x + ((i == 1 || i == 4) ? siz / 2 : 0);
        int ny = y + ((i == 1 || i == 2) ? siz / 2 : 0);
        int nemx = x + siz / 2 - ((i == 2 || i == 3) ? 1 : 0);
        int nemy = y + siz / 2 - ((i == 3 || i == 4) ? 1 : 0);
        if(rfbm != i){
            board[nemx][nemy] = nst;
            if(prnt) cout << "(" << nemx << " , " << nemy << ") , (" <<  nemx << " , " << nemy << ")\n\n";
            dfs(nx , ny , siz / 2 , nemx , nemy);
            continue;
        }
        if(prnt) cout << "(" << nemx << " , " << nemy << ") , (" <<  emx << " , " << emy << ")\n\n";
        dfs(nx , ny , siz / 2 , emx , emy);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n , x , y;
    cin >> n >> x >> y;
    
    n = pow(2 , n);
    
    dfs(1 , 1 , n , x , y);
    board[x][y] = -1;
    
    for(int i = n;i >= 1;i--){
        for(int j = 1; j <= n;j++){
            cout << board[j][i] << " ";
        }
        cout << "\n";
    }
}
