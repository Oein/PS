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

using namespace std;

#define interface struct
#define zx3f 1061109567
#define itn int

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int N;
int left_card[2000];
int right_card[2000];

int max_n = 0;
int memo[2001][2001];

int DFS(int left, int right)
{
    if (left == N || right == N)
    {
        return 0;
    }
    if (memo[left][right] != -1)
        return memo[left][right];

    // 왼쪽 카드 버리는 경우 -> 얻는 점수 없음
    int max_ = DFS(left + 1, right);
    // 둘 다 버리는 경우 -> 얻는 점수 없음
    max_ = max(max_, DFS(left + 1, right + 1));
    // 오른쪽 카드 버리는 경우 -> 오른쪽 카드 만큼 얻음
    if (right_card[right] < left_card[left])
    {
        max_ = max(max_, DFS(left, right + 1) + right_card[right]);
    }

    memo[left][right] = max_;
    return max_;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    memset(memo, -1, sizeof(memo));
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> left_card[i];
    for (int i = 0; i < N; i++)
        cin >> right_card[i];

    // DFS(0, 0, 0);
    // cout << max_n;
    cout << DFS(0, 0);
    return 0;
}