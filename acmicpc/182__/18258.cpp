#include <bits/stdc++.h>
using namespace std;

class CQueue{
    int* arr;
    int front = 0 , near = 0 , capaticy = 0;

public:
    CQueue(int capaticy){
        this->arr = new int[capaticy + 1];
        this->capaticy = capaticy;
    }

    int ajdust(int n){
        if(n >= 0){
            return n % this->capaticy;
        }else{
            while (n < 0)
            {
                n += this->capaticy;
            }
            return n;
        }
    }

    bool is_Empty(){
        return front == near;
    }

    bool is_Full(){
        if(this->ajdust(this->near + 1) == front){
            return true;
        }else{
            return false;
        }
    }

    void push_back(int n){
        //capaticy 를 10000000(?) 으로 해줄거라서 FULL은 발생 안함
        this->arr[this->near] = n;
        this->near++;
    }

    int pop_front(){
        if(is_Empty()) return -1;
        int data = this->arr[this->front];
        this->front++;
        return data;
    }

    int length(){
        return this->ajdust(near - front);
    }

    int get_front(){
        if(this->is_Empty()) return -1;
        return this->arr[this->front];
    }

    int get_near(){
        if(this->is_Empty()) return -1;
        return this->arr[this->ajdust(this->near - 1)];
    }
};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    CQueue q = CQueue(2000000);

    int n = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        string com = "";
        cin >> com;
        if(com == "push"){
            int n = 0;
            cin >> n;
            q.push_back(n);
        }

        if(com == "pop"){
            cout << q.pop_front() << '\n';
        }

        if(com == "size"){
            cout << q.length() << '\n';
        }

        if(com == "empty"){
            cout << (q.is_Empty() == true ? 1 : 0) << '\n';
        }

        if(com == "front"){
            cout << q.get_front() << '\n';
        }

        if(com == "back"){
            cout << q.get_near() << '\n';
        }
    }
}