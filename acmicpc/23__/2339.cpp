#include<iostream>
using namespace std;
 
int B[21][21][2];
 
int available(int s[2], int e[2]) {
    int cnt[3] = { 0, };
    for (int i = s[0]; i <= e[0]; ++i)
        for (int j = s[1]; j <= e[1]; ++j)
            ++cnt[B[i][j][0]];
 
    if (cnt[2] == 0)return 0;
    if (cnt[2] == 1) {
        if (cnt[1] == 0)return 1;
        else return 0;
    }
    if (cnt[1] == 0)return 0;
    return 2;
}
 
int cut(int s[2], int e[2], bool d) {
    int k = available(s, e);
    if (k == 0) return 0;
    if (k == 1) return 1;
 
    int ret = 0, first, second;
    for (int u = s[!d] + 1; u < e[!d]; ++u) {
        bool possible = false;
        for (int v = s[d]; v <= e[d]; ++v) {
            if (B[u][v][!d] == 2) {
                possible = false;
                break;
            }
            if (B[u][v][!d] == 1)possible = true;
        }
        if (!possible)continue;
 
        int tmp1[2][2] = { {e[0],u - 1},{u - 1,e[1]} };
        int tmp2[2][2] = { {s[0],u + 1},{u + 1,s[1]} };
 
        if ((first = cut(s, tmp1[d], !d)) == 0)continue;
        if ((second = cut(tmp2[d], e, !d)) == 0)continue;
 
        ret += (first * second);
    }
    return ret;
}
 
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j) {
        cin >> B[i][j][0];
        B[j][i][1] = B[i][j][0];
    }
 
    int s[] = { 0,0 }, e[] = { n - 1,n - 1 };
    int ans = cut(s, e, 1) + cut(s, e, 0);
 
    if (ans == 0)cout << -1;
    else cout << ans;
}
