#include <bits/stdc++.h>
using namespace std;

class Situraiton {
public:
    int printed = 1;
    int clipboard = 0;
    int used_time = 0;

    Situraiton(int printed , int clipboard , int used_time){
        this->printed = printed;
        this->clipboard = clipboard;
        this-> used_time = used_time;
    }
    
    int getKey(){
        return this->printed * 2000 + this->clipboard;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int S = 0;
    cin >> S;
    
    queue<Situraiton> q;
    set<int> is_pushed;
    
    q.push(Situraiton(1 , 0 , 0));
    
    while(!q.empty()){
        Situraiton now = q.front();
        //cout << now.printed << "  " << now.clipboard << "  " << now.used_time << "\n";
        if(now.printed == S){
            cout << now.used_time << "\n";
            break;
        }
        
        int next_used_time = now.used_time + 1;
        
        //copy
        if(now.printed != now.clipboard){
            Situraiton copied = Situraiton(
                now.printed,
                now.printed,
                next_used_time
            );
            if(is_pushed.find(copied.getKey()) == is_pushed.end()){
                q.push(copied);
                
                is_pushed.insert(copied.getKey());
            }
        }
        
        //paste
        int paste_printed = now.clipboard + now.printed;
        if(now.clipboard > 0){
            if(paste_printed < 2000){
               Situraiton pasted = Situraiton(
                    paste_printed,
                    now.clipboard,
                    next_used_time
               );
                if(is_pushed.find(pasted.getKey()) == is_pushed.end()){
                    q.push(pasted);
                    
                    is_pushed.insert(pasted.getKey());
                }
            }
        }
        
        //remove
        if(now.printed - 1 > 0){
            Situraiton removed = Situraiton(
                now.printed - 1,
                now.clipboard,
                next_used_time
            );
            if(is_pushed.find(removed.getKey()) == is_pushed.end()){
                q.push(removed);
                
                is_pushed.insert(removed.getKey());
            }
        }
        
        q.pop();
    }
}
