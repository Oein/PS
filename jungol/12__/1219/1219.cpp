#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;

// 행 : 세로
// 열 : 가로

int a, b, c, d, e = 0;
vector<int> f;
bool g[1000005] = {
    0,
};

bool able(int wd)
{
    int usedColorPaper = 0;
    int lastCover = -1;
    for (auto now : f)
    {
        if (usedColorPaper > c)
            return false;
        if (now <= lastCover)
            continue;

        lastCover = now + wd - 1;
        usedColorPaper++;
    }

    if (usedColorPaper > c)
        return false;

    return true;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c >> d;
    for (int i = 0; i < d; i++)
    {
        int hang, yul; // y , x
        cin >> hang >> yul;
        e = max(e, hang);
        if (!g[yul])
        {
            f.push_back(yul);
            g[yul] = true;
        }
    }

    sort(f.begin(), f.end());

    int low = e;
    int high = 1000000;
    int md;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (able(mid))
        {
            high = mid - 1;
            md = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << md;
}
