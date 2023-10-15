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

int searoCnt[15];
int garoCnt[15];

Pos triangleStart = {INT_MAX, INT_MAX}, triangleEnd = {-1, -1};
int triH = -1, triW = -1;

bool garoInc(int inc = 2, int inital = -1)
{
    int nowBe = 1;
    if (inital != -1)
        nowBe = inital;
    for (int i = triangleStart.x; i <= triangleEnd.x; i++, nowBe += inc)
        if (garoCnt[i] != nowBe)
            return false;

    return true;
}

bool garoDec(int dec = 2, int inital = -1)
{
    return garoInc(-dec, inital);
}

bool saeroInc(int inc = 2, int inital = -1)
{
    int nowBe = 1;
    if (inital != -1)
        nowBe = inital;
    for (int i = triangleStart.y; i <= triangleEnd.y; i++, nowBe += inc)
        if (searoCnt[i] != nowBe)
            return false;
    return true;
}

bool saeroDec(int dec = 2, int inital = -1)
{
    return saeroInc(-dec, inital);
}

bool saeroIncDec()
{
    if (triH % 2 == 0)
        return false;
    int nowBe = 1;
    for (int i = triangleStart.y; i <= triangleEnd.y; i++)
    {
        if (searoCnt[i] != nowBe)
            return false;
        const int loc = i - triangleStart.y;
        if (loc < triH / 2) // 절반 까지는 증가
            nowBe++;
        else // 절반 이후로는 감소
            nowBe--;
    }

    return true;
}

bool garoIncDec()
{
    if (triW % 2 == 0)
        return false;
    int nowBe = 1;
    for (int i = triangleStart.x; i <= triangleEnd.x; i++)
    {
        if (garoCnt[i] != nowBe)
            return false;
        const int loc = i - triangleStart.x;
        if (loc < triW / 2) // 절반 까지는 증가
            nowBe++;
        else // 절반 이후로는 감소
            nowBe--;
    }

    return true;
}

// 세로 증가 후 감소 && (가로 2 증가 or 감소)
bool tri1()
{
    if (!saeroIncDec())
        return false;
    if (garoInc())
    {
        cout << triangleStart.y << " " << triangleEnd.x << "\n";
        cout << triangleStart.y + triH / 2 << " " << triangleStart.x << "\n";
        cout << triangleStart.y + triH - 1 << " " << triangleEnd.x << "\n";
    }
    else if (garoDec(2, triW * 2 - 1))
    {
        cout << triangleStart.y << " " << triangleStart.x << "\n";
        cout << triangleStart.y + triH / 2 << " " << triangleEnd.x << "\n";
        cout << triangleStart.y + triH - 1 << " " << triangleStart.x << "\n";
    }
    return true;
}

// (세로 2 증가 or 감소) && 가로 증가 후 감소
bool tri2()
{
    if (!garoIncDec())
        return false;
    if (saeroInc())
    {
        cout << triangleStart.y << " " << triangleStart.x + triW / 2 << "\n";
        cout << triangleStart.y + triH - 1 << " " << triangleStart.x << "\n";
        cout << triangleStart.y + triH - 1 << " " << triangleStart.x + triW - 1 << "\n";
    }
    else if (saeroDec(2, triH * 2 - 1))
    {
        cout << triangleStart.y << " " << triangleStart.x << "\n";
        cout << triangleStart.y << " " << triangleStart.x + triW - 1 << "\n";
        cout << triangleStart.y + triH - 1 << " " << triangleStart.x + triW / 2 << "\n";
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 10; i++)
    {
        string line;
        cin >> line;
        line = "0" + line;
        for (int j = 1; j <= line.size(); j++)
        {
            bool now = line[j] == '1';
            if (!now)
                continue;

            searoCnt[i]++;
            garoCnt[j]++;

            triangleStart.x = min(triangleStart.x, j);
            triangleStart.y = min(triangleStart.y, i);

            triangleEnd.x = max(triangleEnd.x, j);
            triangleEnd.y = max(triangleEnd.y, i);
        }
    }

    triW = triangleEnd.x - triangleStart.x + 1;
    triH = triangleEnd.y - triangleStart.y + 1;

    // cout << "W" << triW << " H" << triH << "\n";

    if (tri1())
        return 0;
    if (tri2())
        return 0;
    if (garoDec(1, triW) && saeroInc(1, 1))
    {
        cout << triangleStart.y << " " << triangleStart.x << "\n";
        cout << triangleEnd.y << " " << triangleStart.x << "\n";
        cout << triangleEnd.y << " " << triangleEnd.x << "\n";
        return 0;
    }
    if (garoDec(1, triW) && saeroDec(1, triH))
    {
        cout << triangleStart.y << " " << triangleStart.x << "\n";
        cout << triangleStart.y << " " << triangleEnd.x << "\n";
        cout << triangleEnd.y << " " << triangleStart.x << "\n";
        return 0;
    }
    if (garoInc(1, 1) && saeroInc(1, 1))
    {
        cout << triangleStart.y << " " << triangleEnd.x << "\n";
        cout << triangleEnd.y << " " << triangleStart.x << "\n";
        cout << triangleEnd.y << " " << triangleEnd.x << "\n";
        return 0;
    }
    if (garoInc(1, 1) && saeroDec(1, triH))
    {
        cout << triangleStart.y << " " << triangleStart.x << "\n";
        cout << triangleStart.y << " " << triangleEnd.x << "\n";
        cout << triangleEnd.y << " " << triangleEnd.x << "\n";
        return 0;
    }
    cout << "0";
}

/*
세로가 증가 후 감소 && (가로가 2씩 증가 || 가로가 2씩 감소)
(세로가 2씩 증가 || 세로가 2씩 감소) && 가로가 증가 후 감소
0000000000|0
0000001000|1
0000011000|2
0000111000|3
0001111000|4
0000111000|3
0000011000|2
0000001000|1
0000000000|0
0000000000|0
==========
0001357000

(가로 감소 || 가로 증가) && (세로 감소 || 세로 증가)
00000|0
01111|4
01110|3
01100|2
01000|1
=====
04321
*/