#include <iostream>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

int closetC = 0;

vector<int> use_step;

int memo[21][21][21];
int tcs = 0;

// find lowest cost
int function(int idx , int open_one , int open_two) {
    if (idx >= tcs) { // step에 따라서 마지막 + 1이 호출됬을때
        return 0; 
    }
    if (memo[idx][open_one][open_two] != -1) return memo[idx][open_one][open_two];

    int now_do = use_step[idx];
    int tc1 = abs(open_one - now_do) + function(idx + 1 , now_do , open_two);//  왼쪽으로 옮기기
    int tc2 = abs(open_two - now_do) + function(idx + 1, open_one, now_do); // 오른쪽으로 옮기기
    
    memo[idx][open_one][open_two] = min(tc1, tc2);
    return memo[idx][open_one][open_two];
}

int main() {
    memset(memo, -1, sizeof(memo));
    int open_one = 0;
    int open_two = 0;
    cin >> closetC >> open_one >> open_two >> tcs;

    for (int i = 0; i < tcs; i++) {
        int x_ = 0;
        cin >> x_;
        use_step.push_back(x_);
    }

    cout << function(0 , open_one , open_two);
}
