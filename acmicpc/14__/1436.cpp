#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    
    int num = 667;
    int upped = 1;
    
    while(upped < n){
        while(to_string(num).find("666") == std::string::npos){
            num += 1;
        }
        num += 1;
        upped += 1;
        //cout << "NUM : " << num << "  UPPED : " << upped << "\n";
    }
    
    cout << num - 1;
    /*
    1 : 666   맨 오른쪽
    2 : 1666  맨 오른쪽
    3 : 2666  ...
    4 : 3666
    5 : 4666
    10 : 9666
    11 : 10666
    12 : 11666
    13 : 12666
    14 : 13666
    15 : 14666
    16 : 15666 ...
    17 : 16660 6이 앞에 있는데 3개니까 뒤에 비개
    18 : 16666 다음거 보다 이게더 작고
    ?? : 100666
    ?? : 106660
    ?? : 106666
    ?? : 160666
    ?? : 166600
    ?? : 166660
    ?? : 166666
    */
}