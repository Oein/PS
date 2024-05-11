#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    int out_ = 0;
    bool check[1000001] = {0,};
    for(int i = 0;i < n;i++){
        int a = 0;
        int b = 0;
        int c = 0;
        cin >> a >> b >> c;
        if(!check[a] && !check[b] && !check[c]) out_++;
        check[a] = true;
        check[b] = true;
        check[c] = true;
    }
    cout << out_;
}
