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

string d(string x)
{
    if (false)
        return x;
    else
        return "";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    int STATE = 0;
    // 0 = Nothing
    // 1 = 0으로 시작

    for (int i = 0; i < str.size(); i++)
    {
        // cout << i << "\n";
        char c = str[i];
        if (STATE == 0) // Nothing
        {
            if (c == '0')
                STATE = 1;
            else
                STATE = 2;
            continue;
        }

        if (STATE == 1) // 0
        {
            if (c != '1')
            {
                cout << "NOISE" << d("ST1");
                return 0;
            }
            STATE = 0;
            continue;
        }

        if (STATE == 2) // 1
        {
            if (c != '0')
            {
                cout << "NOISE" << d("ST2");
                return 0;
            }
            STATE = 3;
            continue;
        }

        if (STATE == 3) // 10
        {
            if (c != '0')
            {
                cout << "NOISE" << d("ST3");
                return 0;
            }
            STATE = 4;
            continue;
        }

        if (STATE == 4) // 100
        {
            STATE = 5;
        }

        if (STATE == 5) // 100+
        {
            // 0이 반복 or 1이 반복
            if (c == '1')
                STATE = 6;
            continue;
        }

        if (STATE == 6) // 100+1
        {
            if (c == '0')
                STATE = 1;
            else
                STATE = 7;

            continue;
        }

        if (STATE == 7) // 100+1+
        {
            if (c == '0')
                STATE = 8;
            continue;
        }

        if (STATE == 8) // ...10 이 있음
        {
            if (c == '1') // 1111101 으로 인식
                STATE = 0;
            else // 1111100이 나옴
                STATE = 5;
            continue;
        }
    }

    if (STATE == 0 || STATE == 6 || STATE == 7)
        cout << "SUBMARINE";
    else
        cout << "NOISE";
}
