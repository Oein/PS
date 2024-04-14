#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <numbers>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int N;
int moveK[22];

int moveCnt(int n)
{
    if (n < 2)
        return n;
    int ret = (1 << n) - 1;
    for (int k = 1; k < n; ++k)
    {
        int t = moveCnt(k) * 2 + ((1 << (n - k)) - 1);
        if (t < ret)
        {
            ret = t;
            moveK[n] = k;
        }
    }
    return ret;
}

void hanoi3(int n, int num, int a, int b, int c)
{
    if (n == 0)
        return;
    hanoi3(n - 1, num - 1, a, c, b);
    printf("%d : %c->%c\n", num, a + 64, c + 64);
    hanoi3(n - 1, num - 1, b, a, c);
}

void hanoi4(int n, int a, int b, int c, int d)
{
    if (n == 0)
        return;
    hanoi4(moveK[n], a, c, d, b);
    hanoi3(n - moveK[n], n, a, c, d);
    hanoi4(moveK[n], b, a, c, d);
}

int main()
{
    cin >> N;
    int ans = moveCnt(N);
    cout << ans << "\n";
    hanoi4(N, 1, 2, 3, 4);
    return 0;
}