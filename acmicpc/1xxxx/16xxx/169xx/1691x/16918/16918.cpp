#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <stack>
#include <cstring>
#include <climits>

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Pos
{
    int x;
    int y;
};

int r,c,n;

vector<vector<int>> board;

const int EMPTY = -1;

bool isin(int y, int x) {
    return 0 <= y && y < r && 0 <= x && x < c;
}

void boomoper(int boomTick) {
    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            if(board[i][j] != boomTick) continue;

            for(int d = 0;d < 4;d++) {
                int ny = i + dy[d];
                int nx = j + dx[d];

                if(!isin(ny, nx)) continue;
                int &bdt = board[ny][nx];
                // 0,2
                if((d == 0 || d == 2) &&  bdt == board[i][j]) {
                    continue;
                } else {
                    bdt = EMPTY;
                }
            }

            board[i][j] = EMPTY;
        }
    }
}

void instoper(int tick) {
    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            if(board[i][j] == EMPTY) board[i][j] = tick;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> n;
    for(int i = 0;i < r;i++) {
        string bd = "";
        cin >> bd;
        vector<int> v;
        for(int j = 0;j < bd.size(); j++) {
            char x = bd[j];
            if(x == 'O') {
                v.push_back(0);
            } else {
                v.push_back(EMPTY);
            }
        }

        board.push_back(v);
    }

    n--;

    for(int i = 0;i < n;i++) {
        const int NOWTICK = 2 + i;
        if(i % 2 == 0) instoper(NOWTICK);
        if(i % 2 == 1) boomoper(NOWTICK - 3);

        // cout << "tick " << NOWTICK << endl;
        // for(int i = 0;i < r;i++) {
        //     for(int j = 0;j < c;j++) {
        //         if(board[i][j] == EMPTY) cout << '.';
        //         else cout << board[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }

    for(int i = 0;i < r;i++) {
        for(int j = 0;j < c;j++) {
            if(board[i][j] == EMPTY) cout << '.';
            else cout << 'O';
        }
        cout << endl;
    }
}
