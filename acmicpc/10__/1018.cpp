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

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int h, w;
    cin >> h >> w;
    vector<string> board;
    for(int i = 0 ;i < h;i++) {
        string b;
        cin >> b;
        board.push_back(b);
    }
    int ans = zx3f;
    for(int x = 0; x < w - 7;x++) {
        for(int y = 0;y < h - 7;y++) {
            int da = 0, db = 0;
            for(int i = 0;i < 8;i++)
                for(int j = 0;j < 8;j++) {
                    if((i + j) % 2 == 0) {
                        if(board[i + y][j + x] != 'B')
                            da++;
                        if(board[i + y][j + x] != 'W')
                            db++;
                    } else {
                        if(board[i + y][j + x] != 'W')
                            da++;
                        if(board[i + y][j + x] != 'B')
                            db++;
                    }
                }
            ans = min(ans, min(da, db));
        }
    }
    cout << ans;
}
