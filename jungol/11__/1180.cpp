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
typedef pair<int , int> pii;

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

/*
 원래 N(1 ~ 15)가
 베타에서 N(115)


 문제 조건
 1 <= N <= 15
*/

int n , cnt;

char YunSanJa[23];

void dfs(int step , ll calced , ll num) {
    if(step > n) {
        if(calced + num == 0) {
            cnt++;
            if(cnt > 20) return;

            cout << "1 ";
            for(int i = 2;i <= n;i++) {
                cout << YunSanJa[i] << " " << i << " ";
            }
            cout << "\n";
        }

        return;
    }

    YunSanJa[step] = '+';
    dfs(step + 1 , calced + num , step);
    YunSanJa[step] = '-';
    dfs(step + 1, calced + num, -step);
    YunSanJa[step] = '.';
    int t = step;
    int multi = 10;
    if(step >= 10) multi = 100;
    if(num < 0) t = -t;
    dfs(step + 1 , calced , num * multi + t);
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    dfs(2 , 0 , 1);
    cout << cnt;
}