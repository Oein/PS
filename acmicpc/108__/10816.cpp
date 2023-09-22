#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M;
int cardnum[500000];
int scardnum[500000];

bool stest(int x,int n){
    return x > n - 1;
}

bool etest(int x,int n){
    return x > n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> cardnum[i];
    }
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> scardnum[i];
    }
    sort(&cardnum[0],&cardnum[N]);

    int s =0;
    int e =N;
    int s_ret = 0;
    int e_ret = 0;
    int mid = -1;
    for(int i=0;i<M;i++){
        s_ret = -1;
        e_ret = -1;

        //! 첫 번째 scardnum[i]   -> s
        s = 0;
        e = N;
        while(s < e){
            mid = (s + e) /2;
            if(stest(cardnum[mid], scardnum[i])){
                s_ret = mid;
                e = mid;
            }
            else {
                s = mid + 1;
            }
        }


        
        //! 첫 번째 scardnum[i] 보다 큰 숫자.   ->  e
        s = 0;
        e = N;
        while(s < e){
            mid = (s+e)/2;
            if(etest(cardnum[mid], scardnum[i])){
                e_ret = mid;
                e = mid;
            }
            else {
                s = mid+1;
            }
        }



        //! e - s
        if(s_ret != -1) {
            //! s_ret 찾았음.
            if(cardnum[s_ret] != scardnum[i]) {
                //! 검사해보니 아닌경우.
                cout << 0 << ' ';
            }
            else {
                //! 검사해보니 맞았어.
                if(e_ret != -1){
                    //! e_ret 찾은 경우.
                    cout << e_ret - s_ret << ' ';
                }
                else {
                    //! e_ret 못찾은 경우.
                    cout << N - s_ret << ' ';
                }
            }
        }
        else {
            //! s_ret 못찾았음.
            cout << 0 << ' ';
        }
    }
}