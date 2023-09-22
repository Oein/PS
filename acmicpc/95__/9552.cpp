// mem 초과
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

/*
 0  1  2
 3  4  5
 6  7  8
 9  10 11
 */

int validN[13];
const int MAX_L = 5*12;
int dp[12][(1 << 12)][MAX_L];

int dist(int a, int b) {
    int ay = a / 3, ax = a % 3;
    int by = b / 3, bx = b % 3;
    return abs(ax - bx) + abs(ay - by);
}

bool can_go(int a , int b , int used){
    int ay = a / 3, ax = a % 3;
    int by = b / 3, bx = b % 3;
    
    if(abs(ax - bx) == 2 && abs(ay - by) == 2){
        int mx = 1;
        int my = (ay + by) / 2;
        if(used & (1 << (mx + my * 3))){
            return true;
        }
        return false;
    }

    if(ay == by && abs(ax - bx) == 2){
        return (used & (1 << (1 + ay * 3)));
    }

    if(ax == bx){
        if(by < ay) swap(ay , by);
        for(int i = ay + 1;i < by;i++){
            if(!(used & (1 << (ax + i * 3)))){
                return false;
            }
        }
    }
    
    return true;
}

int f(int now , int used , int left){
    if(left == 0) return 1;
    int& rt = dp[now][used][left];
    if(rt != -1) return rt;
    rt = 0;
    for(int i = 0;i < 12; i++){
        if(i != now){
            if(!validN[i] || (used & (1 << i)) || dist(now , i) > left || !can_go(now , i , used)) { // if it is not valid
                continue;
            }
            rt += f(i , used | (1 << i) , left - dist(now, i));
        }
    }
    return rt;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(validN, true, sizeof(validN));
        memset(dp , -1 , sizeof(dp));
        
        int l , n;
        cin >> l >> n;
        
        while(n--){
            int x , y;
            cin >> x >> y;
            x--;
            y--;
            validN[(x + y * 3)] = false;
        }

        if(l >= MAX_L){
            cout << "BAD MEMORY" << "\n";
            continue;
        }
        
        int r = 0;
        for (int i = 0; i < 12; i++)
            if (validN[i])
                r += f(i, 1 << i , l);
        if (r)
            cout << r << "\n";
        else
            cout << "BAD MEMORY" << "\n";
    }
}