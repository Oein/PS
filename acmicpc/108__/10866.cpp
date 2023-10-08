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

deque<int> x;

void front()
{
    if (x.empty())
        cout << -1 << '\n';
    else
        cout << x.front() << '\n';
}

void back()
{
    if (x.empty())
        cout << -1 << '\n';
    else
        cout << x.back() << '\n';
}

void empty()
{
    cout << (x.empty() ? 1 : 0) << '\n';
}

void size()
{
    cout << x.size() << '\n';
}

void push_front()
{
    int y;
    cin >> y;
    x.push_front(y);
}

void push_back()
{
    int y;
    cin >> y;
    x.push_back(y);
}

void pop_front()
{
    if (x.empty())
        cout << -1 << '\n';
    else
    {
        cout << x.front() << '\n';
        x.pop_front();
    }
}

void pop_back()
{
    if (x.empty())
        cout << -1 << '\n';
    else
    {
        cout << x.back() << '\n';
        x.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string cmd;
        cin >> cmd;
        if (cmd[0] == 'f')
            front();
        if (cmd[0] == 'b')
            back();
        if (cmd[0] == 's')
            size();
        if (cmd[0] == 'e')
            empty();
        if (cmd[0] == 'p')
        {
            if (cmd[1] == 'u')
            {
                if (cmd.size() == 10)
                    push_front();
                else
                    push_back();
            }
            if (cmd[1] == 'o')
            {
                if (cmd.size() == 9)
                    pop_front();
                else
                    pop_back();
            }
        }
    }
}
