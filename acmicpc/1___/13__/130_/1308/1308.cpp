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

bool isLearYear(int year)
{
    bool case1 = year % 4 == 0;
    bool case2 = year % 100 == 0;
    bool case3 = year % 400 == 0;
    if (case3)
        return 1;
    if (case2)
        return 0;
    if (case1)
        return 1;
    return 0;
}

bool isBeforeLeap(int m, int d)
{
    if (m >= 3)
        return false;
    if (d == 29 && m == 2)
        return false;
    return true;
}

int getMonthd(int y, int m)
{
    if (m == 1)
        return 31;
    if (m == 2)
    {
        if (isLearYear(y))
            return 29;
        return 28;
    }
    if (m == 3)
        return 31;
    if (m == 4)
        return 30;
    if (m == 5)
        return 31;
    if (m == 6)
        return 30;
    if (m == 7)
        return 31;
    if (m == 8)
        return 31;
    if (m == 9)
        return 30;
    if (m == 10)
        return 31;
    if (m == 11)
        return 30;
    if (m == 12)
        return 31;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int year, month, day;
    cin >> year >> month >> day;
    int tyear, tmonth, tday;
    cin >> tyear >> tmonth >> tday;
    if (tyear - year == 1000 && tmonth >= month && tday >= day)
    {
        cout << "gg";
        return 0;
    }
    if (tyear - year > 1000)
    {
        cout << "gg";
        return 0;
    }
    int reqdate = 0;
    // 년도가 같은 경우
    if (year == tyear)
    {
        if (month == tmonth)
        {
            reqdate += tday - day;
        }
        else
        {
            for (int nowMonth = month + 1; nowMonth < tmonth; nowMonth++)
            {
                reqdate += getMonthd(year, nowMonth);
            }
            reqdate += getMonthd(year, month) - day;
            reqdate += tday;
        }

        cout << "D-" << reqdate;
        return 0;
    }
    // 통째로 쓰는 년은 그대로 처리
    for (int nowYear = year + 1; nowYear < tyear; nowYear++)
    {
        if (isLearYear(nowYear))
            reqdate += 366;
        else
            reqdate += 365;
    }

    // 마지막 년도 처리
    for (int nowMonth = month + 1; nowMonth <= 12; nowMonth++)
    {
        reqdate += getMonthd(year, nowMonth);
    }
    reqdate += getMonthd(year, month) - day;
    for (int nowMonth = 1; nowMonth < tmonth; nowMonth++)
    {
        reqdate += getMonthd(tyear, nowMonth);
    }
    reqdate += tday;
    cout << "D-" << reqdate;
}
