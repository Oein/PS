#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int ucoc[100010]; // used count of c o i n s
int cp[110]; // coins's price

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) cin >> cp[i];

    for (int i = 1; i <= K; i++) ucoc[i] = 0;

    ucoc[0] = 1;

    for (int i = 1; i <= N; i++) // i 번째 코인을 사용
    {
        for (int j = cp[i]; j <= K; j++) // 해서 j를 만듬
        {
            ucoc[j] = ucoc[j] + ucoc[j - cp[i]]; // 개수 더하기 해야됨
        }
    }

    cout << ucoc[K] << endl;
}
