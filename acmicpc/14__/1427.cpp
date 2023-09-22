#include <bits/stdc++.h>
using namespace std;

bool compare(const char left , const char right){
    return left > right;
}

int main()
{
    string num = "";
    cin >> num;
    sort(num.begin() , num.end() , compare);
    cout << num;
}