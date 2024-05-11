#include <bits/stdc++.h>

using namespace std;


/*
            2
        4       6
    5   4   3   8
*/

class Tree {
public:
    int64_t* nodes_arr;
    int last_index = 1;
    Tree(int len) {
        this->nodes_arr = new int64_t[len + 1];
        for (int i = 0; i < len; i++) {
            this->nodes_arr[i] = INT64_MAX;
        }
    }

    void insert(int64_t data) {
        //data를 빈 곳중 처음에 넣는다.
        this->nodes_arr[last_index] = data;

        int cursor = last_index;

        while (true) {
            // 부모 인덱스 , 자신의 인덱스
            int parant_index = cursor / 2;

            if (this->nodes_arr[parant_index] > this->nodes_arr[cursor] && parant_index != 0) {
                this->swap(parant_index, cursor);
                cursor /= 2;
            }
            else {
                break;
            }
        }

        this->last_index++;
    }

    int64_t get() {
        return this->nodes_arr[1];
    }

    void swap(int a_index, int b_index) {
        int64_t c = this->nodes_arr[a_index];
        this->nodes_arr[a_index] = this->nodes_arr[b_index];
        this->nodes_arr[b_index] = c;
    }

    void pop() {
        this->nodes_arr[1] = INT64_MAX;

        this->swap(1, this->last_index - 1);
        this->last_index--;


        int cursor = 1;

        while (true)
        {
            int left_index = cursor * 2;
            int right_index = cursor * 2 + 1;

            bool is_left_small = this->nodes_arr[left_index] < this->nodes_arr[right_index];

            if (is_left_small) {
                if (this->nodes_arr[left_index] < this->nodes_arr[cursor]) {
                    this->swap(left_index, cursor);
                    cursor = left_index;
                }
                else {
                    return;
                }
            }
            else {
                if (this->nodes_arr[right_index] < this->nodes_arr[cursor]) {
                    this->swap(right_index, cursor);
                    cursor = right_index;
                }
                else {
                    return;
                }
            }
        }
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);



    int n = 0 , m = 0;
    cin >> n >> m;

    Tree tree(n * 2);

    for (int i = 0; i < n; i++) {
        int64_t temp = 0;
        cin >> temp;
        tree.insert(temp);
    }

    for (int i = 0; i < m; i++) {
        int64_t min_a = tree.get();
        tree.pop();

        int64_t min_b = tree.get();
        tree.pop();

        tree.insert(min_a + min_b);
        tree.insert(min_a + min_b);
    }

    int64_t all = 0;

    for (int i = 0; i < n; i++) {
        all += tree.get();
        tree.pop();
    }

    cout << all << '\n';
}