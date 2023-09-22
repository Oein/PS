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
typedef vector<int> vi;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

/*
    ***** = 한줄에 (0 ~ 2)

    .*....
    .*****
    .*....
    *****.
    .*....
 */

string board[8];
int preFix[8][12];
int placeAble[15];
bool placed[15];
int height, width, ans = 100;
int needs = 0;

int calc()
{
    int nds = 0;
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            if (preFix[i][j] && !placed[j])
            {
                int k;
                for (k = j; k <= width && k < j + 5 && preFix[i][k]; ++k)
                {
                }
                nds++;
                j = k - 1;
                if (preFix[i][j] < 5)
                    return 100;
            }
        }
    }

    return nds;
}

void dfs(int step)
{
    if (step > width)
    {
        ans = min(ans, needs + calc());
        return;
    }

    dfs(step + 1); // 놓지 않기

    if (placeAble[step] < 5)
        return;
    // 놓기
    placed[step] = 1;
    needs++;
    dfs(step + 1);
    needs--;
    placed[step] = 0;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> height >> width;
    for (int i = 1; i <= height; i++)
    {
        cin >> board[i];
        board[i] = " " + board[i];
    }

    bool exsistStar = false;

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            if (board[i][j] == '.')
                continue;
            preFix[i][j] = preFix[i][j - 1];
            preFix[i][j]++;
            placeAble[j]++;
            exsistStar = 1;
        }
    }

    if (height <= 4 && width <= 4 && exsistStar)
    {
        cout << "-1";
        return 0;
    }

    dfs(1);
    if (ans == 100)
        cout << "-1";
    else
        cout << ans;
}