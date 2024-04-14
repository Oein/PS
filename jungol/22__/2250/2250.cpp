#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <numbers>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int board[6][6];

/*
 @desc "struct for ans"
 */
struct Data
{
    int direction;
    int many;
    int where;
};

Data ans[10];

Data savedAns[10];
int savedStep = 100;
bool haveAns = false;

/**
 * @brief Return "different number count"
 *
 * @return int "different number count"
 */
int diff()
{
    int difs = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (board[i][j] != (i - 1) * 4 + j)
                difs++;
        }
    }

    return difs;
}

/**
 * @brief Input
 *
 */
void input()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> board[i][j];
        }
    }
}

/**
 * @brief Push board
 *
 * @param where
 */
void push_x(int where)
{
    int z = board[where][4];
    board[where][4] = board[where][3];
    board[where][3] = board[where][2];
    board[where][2] = board[where][1];
    board[where][1] = z;
}

/**
 * @brief Push board
 *
 * @param where
 */
void push_y(int where)
{
    int z = board[4][where];
    board[4][where] = board[3][where];
    board[3][where] = board[2][where];
    board[2][where] = board[1][where];
    board[1][where] = z;
}

/**
 * @brief Push the board
 *
 * @param d
 */
void push(Data d)
{
    if (d.direction == 1)
    {
        for (int i = 0; i < d.many; i++)
        {
            push_x(d.where);
        }
    }

    if (d.direction == 2)
    {
        for (int i = 0; i < d.many; i++)
        {
            push_y(d.where);
        }
    }

    if (d.direction == 3)
    {
        for (int i = 0; i < 4 - d.many; i++)
        {
            push_x(d.where);
        }
    }

    if (d.direction == 4)
    {
        for (int i = 0; i < 4 - d.many; i++)
        {
            push_x(d.where);
        }
    }
}

/**
 * @brief Solve with dfs
 *
 * @param step Step
 */
void dfs(int step)
{
    // End statement
    if (savedStep < step)
        return;

    int different_element_count = diff();

    // Completed
    if (different_element_count == 0)
    {
        savedStep = step;
        for (int i = 0; i < step; i++)
        {
            savedAns[i] = ans[i];
        }
        haveAns = true;
        return;
    }

    // End statement
    if (step + (different_element_count / 4) - 1 > 7)
        return;
    if (step > 7)
        return;

    for (int dir = 1; dir <= 2; dir++)
    {
        ans[step].direction = dir;
        for (int where = 1; where <= 4; where++)
        {
            ans[step].where = where;
            for (int many = 1; many <= 3; many++)
            {
                // Push forward
                ans[step].many = many;
                push(ans[step]);

                // Do Again
                dfs(step + 1);

                // Push backward
                ans[step].many = 4 - many;
                push(ans[step]);
            }
        }
    }
}

/**
 * @brief 어쩔 아웃
 *
 */
void output()
{
    cout << savedStep - 1 << "\n";
    for (int i = 1; i < savedStep; i++)
    {
        cout << savedAns[i].direction << " " << savedAns[i].where << " " << savedAns[i].many << "\n";
    }
}

/**
 * @brief 어쩔 메인 함수
 *
 * @return int
 */
int main()
{
    cin.tie(0);
    cout.tie(0);

    input();

    dfs(1);

    if (haveAns)
        output();
}