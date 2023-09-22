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
typedef pair<pair<int , int> , pair<int , int>> ppi_i__pi_i;
typedef pair<long long , long long> pll_ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> ms_i;
typedef map<string , string> ms_s;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

int r , c;
/*
 * r : 세로
 * c : 가로
 */

string board[27];

// comeToMe[ 0 : 왼쪽 , 1 : 오른쪽 , 2 : 위 , 3 : 아래][?]
char comeToMe[5][5] = { { '-' , '1' , '2' , '+' } , { '-' , '3' , '4' , '+' } , { '|' , '1' , '4' , '+' } , { '|' , '2' , '3' , '+' } };
int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , -0 , -1 , 1};

char needBlock[3][3][3][3] = {
    { // 0 : 왼쪽 없음
        { // 0 : 오른쪽 없음
            { // 0 : 위에 없음
                '.',
                '.'
            },
            { // 1 : 위에 있음
                '.',
                '|'
            }
        },
        { // 1 : 오른쪽 있음
            { // 0 : 위에 없음
                '.',
                '1'
            },
            { // 1 : 위에 있음
                '2',
                '.'
            }
        }
    },
    { // 1 : 왼쪽 있음
        { // 0 : 오른쪽 없음
            { // 0 : 위에 없음
                '.',
                '4'
            },
            { // 1 : 위에 있음
                '3',
                '.'
            }
        },
        { // 1 : 오른쪽 있음
            { // 0 : 위에 없음
                '-',
                '.'
            },
            { // 1 : 위에 있음
                '.',
                '+'
            }
        }
    }
};

bool isInside(int x , int y){
    return x >= 0 && y >= 0 && x < c && y < r;
}

bool isRealEmpty(int x , int y){
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!isInside(nx , ny)) continue;

        bool isLokingAtMe = false;
        for(int j = 0;j < 4;j++){
            if(board[ny][nx] == comeToMe[i][j]){
                return false;
            }
        }
    }
    return true;
}

int isToMe(int x , int y , int rotation){
    for(int j = 0;j < 4;j++){
        if(board[y][x] == comeToMe[rotation][j]){
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> r >> c;

    for(int i = 0;i < r;i++){
        cin >> board[i];
    }

    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            // i = 세로
            // j = 가로
            if(board[i][j] == 'M' || board[i][j] == 'Z' || board[i][j] != '.') continue;
            if(isRealEmpty(j , i)) continue;

            int i1 = 0;
            if(isInside(j - 1 , i)){ // left
                i1 = isToMe(j - 1 , i , 0);
            }

            int i2 = 0;
            if(isInside(j + 1 , i)){ // right
                i2 = isToMe(j + 1 , i , 1);
            }

            int i3 = 0;
            if(isInside(j , i - 1)){ // up
                i3 = isToMe(j , i - 1 , 2);
            }

            int i4 = 0;
            if(isInside(j , i + 1)){ // down
                i4 = isToMe(j , i + 1 , 3);
            }
            cout << i + 1 << " " << j + 1 << " " << needBlock[i1][i2][i3][i4];
            return 0;
        }
    }
}