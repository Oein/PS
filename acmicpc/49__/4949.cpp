#include <iostream>
#include <vector>
using namespace std;

int main(){
    while(true){
        string input_ = "";
        vector<char> last;
        bool ok = true;
        
        getline(cin , input_);

        if(input_ == "."){
            return 0;
        }
        
        for(int i = 0;i < input_.size();i++){
            if(input_[i] == '('){
                last.push_back('(');
            }
            if(input_[i] == '['){
                last.push_back('[');
            }
        
            if(input_[i] == ')'){
                if(last.size() == 0){
                    ok = false;
                }
                else if(last[last.size() - 1] != '('){
                    ok = false;
                    last.pop_back();
                }
                else{
                    last.pop_back();
                }
            }
        
            if(input_[i] == ']'){
                if(last.size() == 0){
                    ok = false;
                }
                else if(last[last.size() - 1] != '['){
                    ok = false;
                    last.pop_back();
                }
                else{
                    last.pop_back();
                }
            }
            
            if(input_[i] == '.'){
                if(last.size() > 0) cout << "no\n";
                else if(ok) cout << "yes\n";
                else cout << "no\n";
            }
        }
    }
}
