#include <bits/stdc++.h>
using namespace std;

int t = 0; //testCase
int m = 0; //X
int n = 0; //Y
int k = 0; //BaeChu
int warmCount = 0;

int farmMap[51][51] = {{0,} ,};
bool isWarmSpreded[51][51] = {{false,},};

int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};

void initFarmMap(){
    for(int i = 0;i < 50;i++){
        for(int j = 0;j < 50;j++){
            farmMap[i][j] = 0;
            isWarmSpreded[i][j] = 0;
        }
    }
}

bool isInside(int x , int y){
    if(x < 0 || x > m){
        return false;
    }
    if(y < 0 || y > n){
        return false;
    }
    
    return true;
}

void spreadWarm(int x , int y){ // x , y좌표에 배추가 있다고 가정
    if(isWarmSpreded[x][y]) //이미 지렁이가 갔던곳이면
        return;
    isWarmSpreded[x][y] = true;
    for(int i = 0;i < 4;i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(isInside(newX, newY)){ //안에 있고
            if(farmMap[newX][newY] == 1){ //거기에 배추가 있고
                spreadWarm(newX, newY);
            }
        }
    }
}

void BFS(){
    for(int i = 0;i < n;i++){ // i == y좌표
        for(int j = 0;j < m;j++){ // j = x좌표
            if(farmMap[j][i] == 1){
                if(isWarmSpreded[j][i] == false){
                    spreadWarm(j, i);
                    warmCount++;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    
    for(int i = 0;i < t;i++){
        initFarmMap();
        warmCount = 0;
        
        cin >> m >> n >> k;
        
        for(int j = 0;j < k;j++){
            int baeChuX = 0;
            int baeChuY = 0;
            
            cin >> baeChuX >> baeChuY;
            
            farmMap[baeChuX][baeChuY] =  1;
        }
        
        BFS();
        
        cout << warmCount << "\n";
    }
}
