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

int board[10][10];
int rowSum[10] = {
    0,
};
int colSum[10] = {
    0,
};
int n;
int allSum = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> board[i][j];
            board[i][j] -= n;
            allSum += board[i][j];
            rowSum[i] += board[i][j];
            colSum[j] += board[i][j];
        }
    }

    // cout << "AllSum: " << allSum << "\n";
    allSum /= 15;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int x = -(2 * allSum + 7 * board[i][j] - rowSum[i] - colSum[j]) / 7;

            if (x == 0)
                cout << ".";
            else if (x == 1)
                cout << "+";
            else
                cout << "-";
            cout << " ";
        }

        cout << "\n";
    }
}
