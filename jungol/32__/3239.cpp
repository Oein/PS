#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <numbers>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

struct D {
    int data;
    int index;

    bool operator < (const D& other) const {
        if(data == other.data) return index < other.index;
        return data < other.data;
    };
};

int arr[100005 * 2];
D tree[100005 * 4];
int etd = 1000000002;

int mn = 0;
inline D Min(D a, D b){ return a < b ? a : b; } 
void build (int now, int s, int e){
    if (s == e){ 
        D x;
        x.data = arr[s];
        x.index = s;
        tree[now] = x;
        return;
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    build(lch, s, m);
    build(rch, m + 1, e);
    tree[now] = Min(tree[lch], tree[rch]);
}

void update(int now, int s, int e, int tgIdx, int val){
    if (s == e){
        tree[now].data = val;
        return;
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    if ( tgIdx <= m) update(lch, s, m, tgIdx, val );
    else update(rch, m + 1, e, tgIdx, val );
    tree[now] = Min(tree[lch], tree[rch]);
}

D query(int now, int s, int e, int fs, int fe){
    if (e < fs || fe < s) {
        D x = {etd , -1};
        return x;
    }
    if (fs <= s && e <= fe) return tree[now];
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    D left = query(lch, s, m, fs, fe);
    D right = query(rch, m + 1, e, fs, fe);
    return Min(left, right);
}

int n , m;

void CMD1() {
    int k , v;
    cin >> k >> v;
    arr[k] = v;
    update(1 , 1 , n , k , v);
}

void CMD2() {
    int s , e;
    cin >> s >> e;
    D qd = query(1 , 1 , n , s , e);
    if(qd.data != etd) {
        cout << qd.index << "\n";
    }
}

void CMD3() {
    int s , e;
    cin >> s >> e;
    D qd = query(1 , 1 , n , s , e);
    arr[qd.index] = etd;
    update(1 , 1 , n , qd.index , etd);
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    fill(arr , arr + n + 1 , etd);
    build(1 , 1 , n);
    for(int i = 0;i < m;i++) {
        int cmd;
        cin >> cmd;
        if(cmd == 1) CMD1();
        else if(cmd == 2) CMD2();
        else if(cmd == 3) CMD3();
    }
}