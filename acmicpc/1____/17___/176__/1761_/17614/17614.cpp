#include <bits/stdc++.h>
using namespace std;

int how_many_three(int the_num){
    int out = 0;
    while (the_num > 0) {
        if(the_num % 10 == 3 || the_num % 10 == 6 || the_num % 10 == 9){
            out++;
        }
        the_num = the_num / 10;
    }
    return out;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 0;
    int clab = 0;
    cin >> n;
    for(int x = 3;x <= n;x++){
        clab = clab + how_many_three(x);
    }
    cout << clab;
}
