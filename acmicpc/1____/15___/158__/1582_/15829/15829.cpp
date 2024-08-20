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

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

struct Pos
{
    int x;
    int y;
};

int cmap[128] = {
    0,
};
int baseNum = 31;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int len;
    string s;
    cin >> len >> s;
    for (int i = 'a'; i <= 'z'; i++)
        cmap[i] = i - 'a' + 1;

    unsigned long long hashed = 0;
    unsigned long long multi = 1;
    for (int i = 0; i < len; i++)
    {
        hashed += (cmap[s[i]] * multi);
        hashed %= 1234567891;
        multi *= baseNum;
        multi %= 1234567891;
    }
    cout << hashed % 1234567891;
}
