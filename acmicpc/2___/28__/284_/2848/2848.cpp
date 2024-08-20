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

vector<string> arr;
bool adj[30][30] = {
    0,
};
int deg[30] = {
    0,
};
bool charUsed[30] = {
    0,
};
int cnt = 0;
int exitType = -1;

void compare(string a, string b)
{
    // 비교하며 간선 생성

    bool sameOne = true;
    for (int i = 0; i < min(a.size(), b.size()); i++)
    {
        if (a[i] == b[i])
            continue;

        int ca = a[i] - 'a';
        int cb = b[i] - 'a';
        if (adj[ca][cb] == 0)
        {
            adj[ca][cb] = 1;
            deg[cb]++;
        }

        sameOne = false;
        break;
    }

    if (sameOne)
    {
        // 같은 친구. 뒤가 다를 수 있음.
        if (a.size() > b.size())
            exitType = 1;
    }
}

void rmain()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        arr.push_back(x);
        for (char y : x)
        {
            charUsed[y - 'a'] = 1;
        }
    }

    for (int i = 0; i < 26; i++)
        if (charUsed[i])
            cnt++;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            compare(arr[i], arr[j]);
            if (exitType == 1)
            {
                cout << "!\n";
                return;
            }
        }

    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (charUsed[i] && deg[i] == 0)
            q.push(i);

    vector<int> ans;
    while (!q.empty())
    {
        if (q.size() >= 2)
        {
            cout << "?\n";
            return;
        }

        int qf = q.front();
        q.pop();

        ans.push_back(qf);
        for (int i = 0; i < 26; i++)
        {
            if (charUsed[i] && adj[qf][i])
            {
                deg[i]--;

                if (deg[i] == 0)
                    q.push(i);
            }
        }
    }

    if (ans.size() != cnt)
    {
        cout << "!\n";
        return;
    }

    for (auto x : ans)
        cout << (char)(x + 'a');
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
    {
        arr.clear();
        memset(adj, 0, sizeof(adj));
        memset(charUsed, 0, sizeof(charUsed));
        memset(deg, 0, sizeof(deg));
        cnt = 0;
        exitType = -1;

        rmain();
    }
}
