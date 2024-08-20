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

vector<vector<bool>> tetremino[] = {
    {{1, 1, 1, 1}},
    {{1, 1},
     {1, 1}},
    {{1},
     {1},
     {1},
     {1}},
    {{1, 0},
     {1, 0},
     {1, 1}},
    {{0, 1},
     {0, 1},
     {1, 1}},
    {{1, 1, 1},
     {1, 0, 0}},
    {{1, 1, 1},
     {0, 0, 1}},
    {{1, 1},
     {0, 1},
     {0, 1}},
    {{1, 1},
     {1, 0},
     {1, 0}},
    {{0, 0, 1},
     {1, 1, 1}},
    {{1, 0, 0},
     {1, 1, 1}},
    {{1, 0},
     {1, 1},
     {0, 1}},
    {{0, 1},
     {1, 1},
     {1, 0}},
    {{0, 1, 1},
     {1, 1, 0}},
    {{1, 1, 0},
     {0, 1, 1}},
    {{1, 1, 1},
     {0, 1, 0}},
    {{0, 1, 0},
     {1, 1, 1}},
    {{0, 1},
     {1, 1},
     {0, 1}},
    {{1, 0},
     {1, 1},
     {1, 0}}};

int height, width;
int board[505][505] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> height >> width;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            cin >> board[i][j];

    int ans = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            for (auto &t : tetremino)
            {
                if (i + t.size() > height)
                    continue;
                if (j + t[0].size() > width)
                    continue;

                int sum = 0;
                for (int x = 0; x < t.size(); x++)
                    for (int y = 0; y < t[0].size(); y++)
                        if (t[x][y])
                            sum += board[i + x][j + y];
                ans = max(ans, sum);
            }

    cout << ans;
}
