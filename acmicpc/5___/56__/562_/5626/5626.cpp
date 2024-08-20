#include <bits/stdc++.h>

using namespace std;

int mackDaeGi[10010];
int before[10010];
int now[10010];

int n = 0;

int nh = 0; // 농협( 현재 높이임 )

void copy_bn() { // run this after 1 step gets done
    for (int i = 0; i <= n / 2 + 1; i++) {
        before[i] = now[i];
    }

    memset(now, 0, sizeof(now));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> mackDaeGi[i];
    /*
    
    key<앞인지 뒤인지 : bool
    ,
    높이 : int>

    out<경우의수 : int>
    
    */

    if (mackDaeGi[0] <= 0) {
        before[0] = 1;
    }
    else {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < n; i++) {
        /*
         * now[before[nh - 1]] // 내려가기
         * now[before[nh]] // 유지하기
         * now[before[nh + 1]] // 올라가기
        */

        if (mackDaeGi[i] == -1) {
            for (int j = 0; j <= n / 2 + 1; j++) { // i번째 칸에 j높이를 맞춤 
                now[j] = before[j]; // 중간
                now[j] += before[j + 1]; // 전에서 내려간거
                now[j] %= 1000000007;
                if (j > 0) now[j] += before[j - 1], now[j] %= 1000000007; // 전에서 올라간거

                
            }
        }
        else {
            now[mackDaeGi[i]] += before[mackDaeGi[i]];
            now[mackDaeGi[i]] += before[mackDaeGi[i] + 1];
            now[mackDaeGi[i]] %= 1000000007;
            if(mackDaeGi[i] > 0) now[mackDaeGi[i]] += before[mackDaeGi[i] - 1], now[mackDaeGi[i]] %= 1000000007; // 전에서 올라오는거
        }
        

        copy_bn();
    }

    cout << before[0];
}
