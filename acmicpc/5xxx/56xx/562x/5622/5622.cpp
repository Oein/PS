#include <bits/stdc++.h>
using namespace std;
int main(){
    int times[] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
    
    string num;
    int result=0;
    cin >> num;
    for (int i = 0; i < num.size(); i++)
        result += times[num[i] - 'A'];
    cout << result;
}
