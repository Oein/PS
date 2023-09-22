#include <iostream>

using namespace std;
typedef long long ll;

int N, M;
int v[110];
int dp[110][1024];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> v[i];
    v[i] = abs(v[i]);
    dp[1][v[i]] = 1; // 자기 자신을 만드는건 1번에
  }

  for (int i = 2; i <= M; i++) // 계속 수 늘리면서
    for (int j = 1; j <= N; j++)
      for (int k = 0; k < 1024; k++) // 1111111111(2) == 1023(10)
        dp[i][k ^ v[j]] |= dp[i - 1][k];

  for (int i = 1023; i >= 0; i--) { // 큰거에서 하나 빼기 하면서 가장 큰거 출력
    if (dp[M][i]) {
      cout << i << "\n";
      return 0;
    }
  }
}