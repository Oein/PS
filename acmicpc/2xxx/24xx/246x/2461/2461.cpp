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

int classCnt, studentCnt;

struct Student
{
    int classNum;
    int ability;
};

vector<Student> students;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> classCnt >> studentCnt;
    students.resize(studentCnt * classCnt);
    for (int i = 0; i < studentCnt * classCnt; i++)
    {
        cin >> students[i].ability;
        students[i].classNum = i / studentCnt;
    }

    sort(students.begin(), students.end(), [](const Student &a, const Student &b)
         { return a.ability < b.ability; });

    for (int i = 0; i < studentCnt * classCnt; i++)
    {
        cout << students[i].ability << " " << students[i].classNum << "\n";
    }
}
