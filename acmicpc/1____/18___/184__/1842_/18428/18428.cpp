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

int n;
vector<vector<char>> board;

const char TEACHER = 'T';
const char STUDENT = 'S';
const char EMPTY = 'X';

const string YES = "YES";
const string NO = "NO";

vector<Pos> teachers;

bool test(Pos p1, Pos p2, Pos p3) {
    for(Pos t: teachers) {
        for (int i = 0; i < 4; i++) {
            int x = t.x;
            int y = t.y;
            while (true) {
                x += dx[i];
                y += dy[i];
                if (x < 0 || x >= n || y < 0 || y >= n) {
                    break;
                }
                if (x == p1.x && y == p1.y) {
                    break;
                }
                if (x == p2.x && y == p2.y) {
                    break;
                }
                if (x == p3.x && y == p3.y) {
                    break;
                }
                if (board[x][y] == STUDENT) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool dfs(vector<Pos> v) {
    if (v.size() == 3) {
        return test(v[0], v[1], v[2]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != EMPTY) {
                continue;
            }
            v.push_back({i, j});
            if (dfs(v)) {
                // cout << "Able with ";
                // for (Pos p: v) {
                //     cout << "(" << p.x << " " << p.y << ") ";
                // }
                // cout << "\n";
                return true;
            }
            v.pop_back();
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.resize(n);
    for (int i = 0; i < n; i++) {
        vector<char> row(n);
        for (int j = 0; j < n; j++) {
            cin >> row[j];
            if (row[j] == TEACHER) {
                teachers.push_back({i, j});
            }
        }
        board[i] = row;
    }

    vector<Pos> v;
    if (dfs(v)) {
        cout << YES;
    } else {
        cout << NO;
    }

    return 0;
}
