# 1308

Problem from [acmicpc](https://www.acmicpc.net/problem/1308)

# Solution

```cpp
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
```

년도가 1000년 이상 차이 나거나, 1000년 차이나고 월, 일이 같거나 크면 gg를 출력하고 종료한다.

```cpp
bool isBeforeLeap(int m, int d)
{
    if (m >= 3)
        return false;
    if (d == 29 && m == 2)
        return false;
    return true;
}
```

2월 29일 이전인지 확인하는 함수이다.

```cpp
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
```

윤년인지 확인하는 함수이다.

```cpp
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
```

월의 일수를 반환하는 함수이다.

# Logic

1. 년도가 같은경우
   1. 월이 같은경우
      - 일만 비교
   2. 월이 다른경우
      - 통쨰로 쓰는 월만 for문으로 돌려서 비교
      - 추가적으로 일도 비교
2. 년도가 다른경우
   - 통쨰로 쓰는 년도만 for문으로 돌려서 비교
   - 통째로 쓰는 월만 for문으로 돌려서 비교
   - 추가적으로 일도 비교
