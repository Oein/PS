#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    vector<int> datas;

    Queue(){
        this->datas.reserve(10000);
    }

    int get_size() { return this->datas.size(); }

    int empty() { return this->datas.size() == 0 ? 1 : 0; }

    int back(){
        if(this->datas.size() == 0) return -1;
        return this->datas[this->datas.size() - 1];
    }

    int front(){
        if(this->datas.size() == 0) return -1;
        return this->datas[0];
    }

    int pop(){
        if(this->datas.size() == 0) return -1;
        int r_data = this->datas[0];
        this->datas.erase(datas.begin());
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

    Queue queue = Queue();

    int n = 0;
    cin >> n;

    for(int i = 0;i < n;i++){
        string command = "";
        cin >> command;
        
        if(command == "pop") cout << queue.pop();
        if(command == "back") cout << queue.back();
        if(command == "front") cout << queue.front();
        if(command == "size") cout << queue.get_size();
        if(command == "empty") cout << queue.empty();
        if(command == "push"){
            int x = 0;
            cin >> x;
            queue.push(x);
            continue;
        }

        cout << "\n";
    }
}