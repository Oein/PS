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

string chars;
bool used[15] = {
    0,
};

string madedStr = "           ";
int ables = 0;
void dfs(int step)
{
    if (step == chars.size())
    {
        ables++;
        return;
    }

    for (int i = 0; i < chars.size(); i++)
    {
        // 사용되었으면 continue
        if (used[i] == 1)
            continue;
        // 전것과 겹치면 continue
        if (step >= 1 && madedStr[step - 1] == chars[i])
            continue;

        used[i] = 1;
        madedStr[step] = chars[i];
        dfs(step + 1);
        used[i] = 0;
    }
}

int factory(int n)
{
    int fac = 1;
    for (int i = 1; i <= n; i++)
    {
        fac *= i;
    }

    return fac;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> chars;

    bool ed = true;
    int charCnts[30] = {
        0,
    };
    for (int i = 0; i < chars.size(); i++)
    {
        if (charCnts[chars[i] - 'a'] >= 1)
        {
            ed = false;
        }
        charCnts[chars[i] - 'a']++;
    }

    if (ed)
    {
        cout << factory(chars.size());
        return 0;
    }

    int divs = 1;
    for (int i = 'a'; i <= 'z'; i++)
    {
        int ri = i - 'a';
        divs *= factory(charCnts[ri]);
    }

    dfs(0);
    cout << ables / divs;
}