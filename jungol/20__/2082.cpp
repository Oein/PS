#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <numeric>
#include <numbers>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

template<typename T>
struct MAX_HEAP {
    vector<T> heap;

    MAX_HEAP(){
        heap.push_back(-1);
    }

    void add(T x) {
        heap.push_back(x);
        int c = heap.size() - 1;
        while(c > 1 && heap[c / 2] < heap[c]) {
            swap(heap[c / 2] , heap[c]);
            c /= 2;
        }
    }

    bool empty() {
        return heap.size() == 1;
    }

    unsigned int size() {
        return heap.size() - 1;
    }

    T at(int idx) {
        return heap[idx];
    }

    T top() {
        return heap[1];
    }

    T pop(){
        T ret = heap[1];
        swap(heap[1] , heap[heap.size() - 1]);

        heap[heap.size() - 1] = 0;

        int p = 1 , c = 2;
        while(c <= heap.size() - 1) {
            if(c < heap.size() - 1 && heap[c + 1] > heap[c]) c++;
            if(heap[c] <= heap[p]) break;
            swap(heap[p] , heap[c]);
            p = c;
            c *= 2;
        }

        heap.pop_back();

        return ret;
    }
};

int main(){
    cin.tie(0); cout.tie(0);

    MAX_HEAP<int> mh;

    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        mh.add(x);
    }

    for(int i = 1;i <= n;i++) {
        cout << mh.at(i) << " ";
    }

    cout << "\n";

    stack<int> s;

    while(!mh.empty()) {
        s.push(mh.pop());
    }

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}