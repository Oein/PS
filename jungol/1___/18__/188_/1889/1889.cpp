#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> pii;

int ans = 0 , n;;

// board[y] = x
// y번째 줄에는 x번째 칸에 queen이 있다
int board[15];

bool ok(int step){
    for(int i = 0;i < step;i++){
        if(board[i] == board[step]) return false; // 위 아래
        if(step - i == abs(board[step] - board[i])) return false; // 대각선
    }
    return true;
}

void st(int step){
    if(step == n){
        ans++;
        return;
    }

    for(int i = 0;i < n;i++){
        board[step] = i;
        if(ok(step)){
            st(step + 1);
        }
        // board[step] 복구는 안해도됨
    }
}

int main(){
    cin >> n;
    st(0);
    cout << ans;
}
