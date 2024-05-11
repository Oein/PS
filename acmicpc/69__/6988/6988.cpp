#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

bool valid[1000010];
vector<int> numbers;

int cnt = 0;

long long int get(int st, int add) {
    long long int ans = 0;
    int cnt = 0;
    // cout << " Pair < " << st << " , " << add << " > \n";
    while (st < 1000001 && valid[st] == true) {
        // cout << "Ans : " << ans << "\n";
        ans += st;
        st += add;
        cnt++;
    }

    if (cnt >= 3) return ans;
    return -1;
}

int main() {
    memset(valid, false, sizeof(valid));

    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int intwo;
        cin >> intwo;
        valid[intwo] = true;
        numbers.push_back(intwo);
    }

    long long int answer = 0;

    for (int now_st = 0; now_st < cnt; now_st++) {
        for (int now_ed = now_st + 1; now_ed < cnt; now_ed++) {
            int dis = numbers[now_ed] - numbers[now_st];
            long long int ans = get(numbers[now_st], dis);
            if (answer < ans) {
                answer = ans;
            }
        }
    }

    cout << answer;
}
