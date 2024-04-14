/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v[2000][2000]; // 로봇들의 가중치
// y , x로 접근

int main()
{
    int m = 0;
    int n = 0;
    cin >> n >> m;
    for (int i = 0; i <n; i++) {
        string str = "";
        cin >> str;
        for (int j = 0; j < m; j++) {
            v[i][j] = str[j] - '0'; // 기중치 넣기
        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int tmp_ans = 0;
            if (j) { // 처음 아니면
                tmp_ans = v[i][j - 1];
                if (i) tmp_ans = max(tmp_ans, v[i - 1][j - 1]);
                if (i < n - 1) tmp_ans = max(tmp_ans, v[i + 1][j - 1]);
                v[i][j] += tmp_ans;
            }
            ans = max(tmp_ans, ans);
        }
    }

    cout << ans;
}
