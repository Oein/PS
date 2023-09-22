#include <iostream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

int board[60][60];
int sum[60][60];
int memo[60][60][60][60];

int getpay(int stx, int sty, int w, int h) {
    int x2 = stx + w - 1;
    int y2 = sty + h - 1;
    return sum[y2][x2] // full
        - sum[y2][stx - 1] // full 왼쪽
        - sum[sty - 1][x2] // full 오른쪽
        + sum[sty - 1][stx - 1]; // 겹치니까
}

int cut(int stx, int sty, int w, int h) { // 부분별로 잘르기 , (stx , sty , edx , edy 로 하니까 뭔가 힘듬)
    if (w == 1 && h == 1) return 0; // 1 * 1 사이즈

    if (memo[stx][sty][w][h] != -1) return memo[stx][sty][w][h];

    int ans = 1234567890;
    int pay = getpay(stx, sty, w, h);

    // cut 가로
    for (int i = 1; i < h; i++) {
        ans = min(ans, cut(stx, sty, w, i) + cut(stx, sty + i, w, h - i) + pay);
    }

    // cut 세로
    for (int i = 1; i < w; i++) {
        ans = min(ans, cut(stx, sty, i, h) + cut(stx + i, sty, w - i, h) + pay);
    }

    memo[stx][sty][w][h] = ans; // 아니 TimeOUT 나서 봤던이 memo 만들고 안쓰고 있었네 ㅋㅋ

    return ans;
}

int main() {
    memset(memo, -1, sizeof(memo));
    memset(sum, 0, sizeof(sum));
    int ysize, xsize;
    cin >> ysize >> xsize;

    for (int i = 1; i <= ysize; i++) {
        for (int j = 1; j <= xsize; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= ysize; i++) { // 세로
        for (int j = 1; j <= xsize; j++) {
            sum[i][j] = sum[i][j - 1] + board[i][j];
            // y가 -1 이 되니까
        }
    }

    for (int i = 1; i <= ysize; i++) { // 가로
        for (int j = 1; j <= xsize; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j];
        }
    }

    cout << cut(1, 1, xsize, ysize);
}
