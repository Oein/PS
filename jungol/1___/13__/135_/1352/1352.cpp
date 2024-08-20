#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include <limits>
#include <string>
#include <cmath>
#include <stack>
#include <climits>
#include <queue>
using namespace std;
using ll = long long;

int n, c;
int w[35];
int sum[35];
bool able[35][40005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> w[i];
        sum[i] = w[i] + sum[i - 1];
    }
    for(int i = 1;i <= n;i++) {
        able[i][w[i]] = 1;
        for(int j = 1;j <= sum[i - 1];j++) {
            if(!able[i - 1][j]) continue;
            // 사용 X
            able[i][j] = 1;
            // 오른쪽에 추가
            able[i][j + w[i]] = 1;
            // 왼쪽에 추가
            able[i][abs(j - w[i])] = 1;
        }
    }
    cin >> c;
    while (c--) {
        int x;
        cin >> x;
        if(x == 0 || able[n][x]) cout << "Y ";
        else cout << "N ";
    }
}
