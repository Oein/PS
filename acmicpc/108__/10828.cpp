#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    vector<int> datas;

    Stack(){
        this->datas.reserve(10000);
    }

    int get_size() { return this->datas.size(); }

    int empty() { return this->datas.size() == 0 ? 1 : 0; }

    int top(){
        if(this->datas.size() == 0) return -1;
        return this->datas[this->datas.size() - 1];
    }

    int pop(){
        if(this->datas.size() == 0) return -1;
        int r_data = this->datas[this->datas.size() - 1];
        this->datas.pop_back();
        return r_data;
    }

    void push(int number){
        datas.push_back(number);
    }
};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    Stack stack = Stack();

    int n = 0;
    cin >> n;

    for(int i = 0;i < n;i++){
        string command = "";
        cin >> command;
        
        if(command == "pop") cout << stack.pop();
        if(command == "top") cout << stack.top();
        if(command == "size") cout << stack.get_size();
        if(command == "empty") cout << stack.empty();
        if(command == "push"){
            int x = 0;
            cin >> x;
            stack.push(x);
            continue;
        }

        cout << "\n";
    }
}