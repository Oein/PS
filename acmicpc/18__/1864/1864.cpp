#include <map>
#include <iostream>

using namespace std;

int main(){
    map<char , int> num;
    
    num.insert(pair<char, int>('-' , 0));
    num.insert(pair<char, int>('\\' , 1));
    num.insert(pair<char, int>('(' , 2));
    num.insert(pair<char, int>('@' , 3));
    num.insert(pair<char, int>('?' , 4));
    num.insert(pair<char, int>('>' , 5));
    num.insert(pair<char, int>('&' , 6));
    num.insert(pair<char, int>('%' , 7));
    num.insert(pair<char, int>('/' , -1));
    
    
    while(true){
        string nm = "";
        cin >> nm;
        
        if(nm == "#") break;
        
        int64_t out_ = 0;
        int64_t mul = 1;
        
        for(int i = nm.size() - 1;i >= 0;i--){
            out_ += num[nm[i]] * mul;
            mul *= 8;
        }
        
        cout << out_ << "\n";
    }
}
