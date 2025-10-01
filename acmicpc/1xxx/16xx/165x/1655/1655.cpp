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

#define endl ('\n')

struct Pos
{
    int x;
    int y;
};

// 작은 수를 저장
// 작은 수중 가장 큰 친구가 앞으로
priority_queue<int, vector<int>, less<int>> pql;
// 큰 수를 저장
// 큰수중 가장 작은 친구가 앞으로
priority_queue<int, vector<int>, greater<int>> pqr;

void rmain()
{
    int num = 0;
    cin >> num;

    // printf("INP %d, LS %d, RS %d\n", num, pql.size(), pqr.size());

    const unsigned long llen = pql.size();
    const unsigned long rlen = pqr.size();

    const int ldata = pql.top();
    const int rdata = pqr.top();

    if (ldata <= num && num <= rdata)
    {
        // l in r
        if (llen == rlen)
        {
            pql.push(num);
        }
        else if (llen > rlen)
        {
            pqr.push(num);
        }
        else
        {
            assert(false);
            cout << "ER!";
        }
    }
    else if (ldata <= num && num > rdata)
    {
        // l r in
        if (llen == rlen)
        {
            pql.push(rdata);
            pqr.pop();
            pqr.push(num);
        }
        else if (llen > rlen)
        {
            pqr.push(num);
        }
        else
        {
            // llen < rlen
            assert(false);
        }
    }
    else if (ldata == num && num == rdata)
    {
        if (llen == rlen)
        {
            pql.push(num);
        }
        else if (llen > rlen)
        {
            pqr.push(num);
        }
        else
        {
            assert(false);
        }
    }
    else if (num < ldata && num < rdata)
    {
        if (llen == rlen)
        {
            pql.push(num);
        }
        else if (llen > rlen)
        {
            pqr.push(ldata);
            pql.pop();
            pql.push(num);
        }
        else
        {
            assert(false);
        }
    }
    else
    {
        printf("L %d, N %d, R %d\n", ldata, num, rdata);
        // assert(false);
    }

    cout << pql.top() << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int inx = 0;
    cin >> inx;
    cout << inx << endl;

    if (n == 1)
    {
        return 0;
    }

    int iny = 0;
    cin >> iny;
    cout << ((inx > iny) ? iny : inx) << endl;
    if (n == 2)
    {
        return 0;
    }

    if (inx < iny)
    {
        pql.push(inx);
        pqr.push(iny);
    }
    else
    {
        pql.push(iny);
        pqr.push(inx);
    }

    n -= 2;

    while (n--)
        rmain();
}
