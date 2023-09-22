#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int , int> pi_i;

bool board[105][105];

int getSi(int y , int x , int ye , int xe){
    int size = 0;
    for(int i = y;i <= ye;i++){ // y
        for(int j = x;j <= xe;j++){ // x
            if(!board[i][j])return 0;
            size++;
        }
    }
    return size;
}

int main(){
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int x , y;
        cin >> x >> y;
        for(int j = 0;j < 10;j++){
            for(int k = 0;k < 10;k++){
                board[y + j][x + k] = 1;
            }
        }
    }

    int maxSum = 0;

    for(int i = 1;i <= 100;i++){ // y
        for(int j = 1;j <= 100;j++){ // x
            if(board[i][j]){
                for(int k = i;k <= 100;k++){ // y 
                    for(int l = j;l <= 100;l++){ // x
                        maxSum = max(maxSum , getSi(i , j , k , l));
                    }
                }
            }
        }
    }

    cout << maxSum;
}