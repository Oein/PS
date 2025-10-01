#include "bits/stdc++.h"
using namespace std;

class Heap {
public:
    int* nodes_arr;
    int last_index = 1;
    function<bool(int, int)> func;
    Heap(int len , function<bool(int,int)> func) {
        this->nodes_arr = new int[len + 1];
        this->func = func;
        for (int i = 0; i < len; i++) {
            this->nodes_arr[i] = INT_MIN;
        }
    }

    void insert(int data) {
        //data를 빈 곳중 처음에 넣는다.
        this->nodes_arr[last_index] = data;

        int cursor = last_index;

        while (true) {
            // 부모 인덱스 , 자신의 인덱스
            int parant_index = cursor / 2;

            if (this->func(this->nodes_arr[parant_index] , this->nodes_arr[cursor] ) && parant_index != 0) { // <
                this->swap(parant_index, cursor);
                cursor /= 2;
            }
            else {
                break;
            }
        }

        this->last_index++;
    }

    void print_nodesArr() {
        for (int i = 1; i < last_index; i++) {
            cout << nodes_arr[i] << "  ";
        }
        cout << "\n";
    }

    int get() {
        return this->nodes_arr[1];
    }

    string all_datas_string() {
        string returned_data = "";
        for (int i = 1; i < this->last_index; i++) {
            returned_data += to_string(this->nodes_arr[i]) + " ";
        }

        return returned_data;
    }

    void swap(int a_index, int b_index) {
        int c = this->nodes_arr[a_index];
        this->nodes_arr[a_index] = this->nodes_arr[b_index];
        this->nodes_arr[b_index] = c;
    }

    void pop() {
        this->nodes_arr[1] = INT_MIN;

        this->swap(1, this->last_index - 1);
        this->last_index--;


        int cursor = 1;

        while (true)
        {
            const int left_index = cursor * 2;
            const int right_index = cursor * 2 + 1;

            const int par_val = this->nodes_arr[cursor];

            if (left_index >= last_index) {
                //없음
                break;
            }
            else if (left_index + 1 >= last_index) {
                //왼쪽만
                const int left_val = this->nodes_arr[left_index];

                if (this->func(par_val, left_val)) {
                    // 최소힙일때 부모가 더큼
                    this->swap(cursor, left_index);
                    break;
                }
            }
            else {
                //둘다
                const int left_val = this->nodes_arr[left_index];
                const int right_val = this->nodes_arr[right_index];

                if (this->func(left_val, right_val)) {
                    //최소힙일때 왼쪽이 더큼 ( 오른쪽과 비교 해야함 )
                    if (this->func(par_val, right_val)) {
                        //부모가 더큼 ( swap 해야함 ) 
                        this->swap(cursor, right_index);
                        cursor = right_index;
                        continue;
                    }
                    else {
                        break;
                    }
                }
                else {
                    //최소힙일때 오른쪽이 더큼 ( 왼쪽과 비교 해야함 )
                    if (this->func(par_val, left_val)) {
                        //부모가 더큼 ( swap 해야함 ) 
                        this->swap(cursor, left_index);
                        cursor = left_index;
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }

            break;
        }
    }
};

int get_abs(int i) {
    return i > 0 ? i : i * -1;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    Heap heap(n * 2, [](int a, int b) {
        if (get_abs(a) != get_abs(b)) {
            return get_abs(a) > get_abs(b);
        }
        else {
            return a > b;
        }
    });

    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;

        if (temp == 0) {
            if (heap.last_index != 1) {
               cout << heap.get() << '\n';
               heap.pop();
            }
            else {
                cout << "0\n";
            }
        }
        else {
            heap.insert(temp);
        }
        // heap.print_nodesArr();
    }
    return 0;
}