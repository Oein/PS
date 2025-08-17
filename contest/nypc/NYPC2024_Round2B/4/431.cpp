#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

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

enum ARTIST
{
    HUMAN = 'h',
    GIANT = 'g',
    ELF = 'e',
};

string str;
int n, q;

void rmain()
{
    int x, s, e;
    char v;
    cin >> x >> v >> s >> e;

    char orig = str[x - 1];
    str[x - 1] = v;

    // 삭제 해야 하는 최소 인원 구하기
    // h와 g,e는 붙어 있을 수 있음
    // g,e는 붙어 있을 수 없음

    char LASTCHAR = str[s - 1];
    int artistCnt = 1;
    int rm = 0;
    set<int> rmtest;
    vector<pair<ARTIST, int>> artistGroup;
    for (int i = s; i < e; i++)
    {
        char c = str[i];

        if (c == LASTCHAR)
        {
            artistCnt++;
            continue;
        }
        else
        {
            artistGroup.push_back({(ARTIST)LASTCHAR, artistCnt});
            artistCnt = 1;
            LASTCHAR = c;
        }
    }
    artistGroup.push_back({(ARTIST)LASTCHAR, artistCnt});

    int elfCnt = 0;
    int giantCnt = 0;
    for (auto i : artistGroup)
    {
        pair<ARTIST, int> now = i;
        // cout << (char)now.first << ' ' << now.second << '\n';
        if (now.first == ARTIST::HUMAN)
        {
            // calculate
            // cout << "ELF: " << elfCnt << " GIANT: " << giantCnt << '\n';
            if (elfCnt > giantCnt)
            {
                rm += giantCnt;
            }
            else
            {
                rm += elfCnt;
            }

            elfCnt = 0;
            giantCnt = 0;
        }
        else
        {
            if (now.first == ARTIST::ELF)
            {
                elfCnt += now.second;
            }
            else
            {
                giantCnt += now.second;
            }
        }
    }
    // cout << "ELF: " << elfCnt << " GIANT: " << giantCnt << '\n';
    if (elfCnt > giantCnt)
    {
        rm += giantCnt;
    }
    else
    {
        rm += elfCnt;
    }
    // cout << '\n';
    cout << rm << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> str;

    for (int i = 0; i < q; i++)
    {
        // cout << "==================\n";
        rmain();
    }
}
