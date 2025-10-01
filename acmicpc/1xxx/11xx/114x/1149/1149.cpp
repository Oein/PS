#include <bits/stdc++.h>

using namespace std;

int price[1001][3];
int main() {

    int N;
    int cost[3]; // 지금까지 가격
    price[0][0] = 0;
    price[0][1] = 0;
    price[0][2] = 0;

    cin >> N; // count
    for (int i = 1; i <= N; ++i)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        price[i][0] = min(price[i - 1][1], price[i - 1][2]) + cost[0]; // R + 전거중 작은거 ( G , B ) 중에서 선택
        price[i][1] = min(price[i - 1][0], price[i - 1][2]) + cost[1]; // G
        price[i][2] = min(price[i - 1][1], price[i - 1][0]) + cost[2]; // B
    }
    cout << min(price[N][2], min(price[N][0], price[N][1])); // R G B 3중 가장 작은거
}