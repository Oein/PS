#include <iostream>
#include <vector>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int cost[4][4] = {
    {100, 70, 40, 0},
    {70, 50, 30, 0},
    {40, 30, 20, 0},
    {0, 0, 0, 0}
};
int board[12][12];
int dp[12][12][1 << 12];
int n , now_bit , right_bit , down_bit , mod_bit;

int f(int i, int j, int bit){    
    if(j == n) {
        j = 0;
        i++;
    }
    if(i == n) return 0;

    int& ret = dp[i][j][bit];
    if(ret != -1) return ret;
    
    ret = 0;
    
    if(!(bit & now_bit)){
        // now bit is not included
        int now_ = board[i][j], next_ = 0, dt;
        
        if(j + 1 < n && !(bit & right_bit)){ // wiint go to 2 right and cut right
            next_ = board[i][j + 1];
            dt = f(i , j + 2 , (bit << 2) % mod_bit) + cost[now_][next_];
            ret = max(ret , dt);
        }
        if(i + 1 < n && !(bit & down_bit)){ // wiint go to right and cut down
            next_ = board[i + 1][j];
            dt = f(i , j + 1 , ((bit | down_bit) << 1) % mod_bit) + cost[now_][next_];
            ret = max(ret , dt);
        }
    }

    int dt = f(i, j+1, (bit << 1) % mod_bit); // skip this block
    ret = max(ret, dt);
    
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    
    now_bit = (1 << n);
    right_bit = (1 << (n - 1));
    down_bit = 1;
    mod_bit = (1 << (n + 1));

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            char x;
            cin >> x;
            board[i][j] = (x <= 'C') ? x - 'A' : 3;
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << f(0 , 0 , 0);
}