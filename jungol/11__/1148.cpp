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

int n;

#define ull unsigned long long

ull segmentTree[500005 * 4];

void updateSeg(ull want2update, ull searchingL, ull searchingR, ull node)
{
    ull mid = (searchingL + searchingR) / 2;
    ull leftEd = mid;
    ull rightSt = mid + 1;

    if (searchingL == want2update && searchingR == want2update)
    {
        segmentTree[node]++;
        return;
    }

    if (searchingL <= want2update && want2update <= mid)
        updateSeg(want2update, searchingL, leftEd, node * 2);
    if (rightSt <= want2update && want2update <= searchingR)
        updateSeg(want2update, rightSt, searchingR, node * 2 + 1);

    segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
    // cout << "update " << node << " to " << segmentTree[node] << "\n";
}

int querySeg(ull wantStart, ull wantEnd, ull searchingL, ull searchingR, ull node)
{
    // cout << "query " << wantStart << " " << wantEnd << " " << searchingL << " " << searchingR << " " << node << "\n";
    ull mid = (searchingL + searchingR) / 2;
    ull leftEd = mid;
    ull rightSt = mid + 1;

    // 쓰래기 값들
    if (wantEnd < searchingL || searchingR < wantStart)
        return 0;

    // 현재 찾고있는 부분이 전부 맞는 값임
    if (wantStart <= searchingL && searchingR <= wantEnd)
    {
        return segmentTree[node];
    }

    // 양쪽 더한값
    return querySeg(wantStart, wantEnd, searchingL, leftEd, node * 2) + querySeg(wantStart, wantEnd, rightSt, searchingR, node * 2 + 1);
}

int enabledCount(int from)
{
    int ret = querySeg(from + 1, n, 1, n, 1);
    // cout << "enabledCount " << from << " " << ret << "\n";
    return ret;
}

vector<int> board;
vector<int> board2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        board.push_back(a);
        board2.push_back(a);
    }
    sort(board2.begin(), board2.end());
    for (int i = 0; i < board.size(); i++)
    {
        // find board[i] in board2
        int idx = lower_bound(board2.begin(), board2.end(), board[i]) - board2.begin();
        board[i] = idx + 1;

        // cout << board[i] << " ";
    }

    ull ans = 0;

    for (int i = 0; i < n; i++)
    {
        ull nna = enabledCount(board[i]); // i번 ~ n까지의 enable 개수
        ans += nna;
        updateSeg(board[i], 1, n, 1); // i번++
    }

    cout << ans;
}
