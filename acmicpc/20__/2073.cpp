#include <iostream>
#include <climits>

using namespace std;
using ll = long long;

int len[351];
int wsize[351];
int dp[100001];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int D, P;
    cin >> D >> P;
    
    for (int i = 0; i < P; i++){
        cin >> len[i] >> wsize[i];
    }
        
    dp[0] = INT_MAX;
    for (int i = 0; i < P; i++) {
        for (int j = D; j >= 0; j--) {
            if (j - len[i] < 0) continue; // 이거 안 넣으면 런타임 에러 (OutOfBounds)
            dp[j] = max(dp[j], min(dp[j - len[i]], wsize[i])); // max(원래 있던거의 싸이즈 , (min(전 파이프의 싸이즈 , 지금 쓸 파이프의 싸이즈)))
            // min(전 파이프의 싸이즈 , 지금 쓸 파이프의 싸이즈) == 작은 파이프의 싸이즈를 써야됨
            // 아 위에꺼 식 만들기 웰케 어렵냐
        }
    }
    cout << dp[D];
    return 0;
}
