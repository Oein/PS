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

int other(int a, int b)
{
    if (a > b)
        swap(a, b);
    if (a == 1 && b == 2)
        return 3;
    if (a == 1 && b == 3)
        return 2;
    if (a == 2 && b == 3)
        return 1;
    return -1;
}

void hanoi(int step, int from, int to)
{
    if (step == 0)
    {
        return;
    }

    hanoi(step - 1, from, other(from, to));
    cout << step << " : " << from << " -> " << to << "\n";
    hanoi(step - 1, other(from, to), to);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    hanoi(n, 1, 3);
}