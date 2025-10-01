#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    cin >> str;
    
    stack<char> stac;
    int out_ = 0;
    for(int i =0; i<str.length();i++){
        if(str[i]=='(') stac.push(str[i]);
        else{
            stac.pop();
            if(str[i-1]=='(')
                out_ += stac.size();
            else out_++;
        }
    }
    
    cout << out_;
}
