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

int arr[100005 * 2];
int tree[100005 * 4];
int etd = -1000000002;

int mn = 0;
inline int Max(int a, int b){ return a>b ? a : b; } 
void build (int now, int s, int e){
    if (s == e){ 
        tree[now] = arr[s];
        return;
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    build(lch, s, m);
    build(rch, m + 1, e);
    tree[now] = Max(tree[lch], tree[rch]);
}

void update(int now, int s, int e, int tgIdx, int val){
    if (s == e){
        tree[now] = val;
        return;
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    if ( tgIdx <= m) update(lch, s, m, tgIdx, val );
    else update(rch, m + 1, e, tgIdx, val );
    tree[now] = Max(tree[lch], tree[rch]);
}

int query(int now, int s, int e, int fs, int fe){
    if (e < fs || fe < s) return etd;
    if (fs <= s && e <= fe) return tree[now];
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    int left = query(lch, s, m, fs, fe);
    int right = query(rch, m + 1, e, fs, fe);
    return max(left, right);
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
    int qd = query(1 , 1 , n , s , e);
    if(qd != etd) {
        cout << qd << "\n";
    }
}

void CMD3() {
    int k;
    cin >> k;
    if(arr[k] != etd) {
        arr[k] = etd;
    }
    update(1 , 1 , n , k , etd);
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    fill(arr , arr + n + 1 , etd);
    fill(tree , tree + n + 1 , etd);
    build(1 , 1 , n);
    for(int i = 0;i < m;i++) {
        int cmd;
        cin >> cmd;
        if(cmd == 1) CMD1();
        else if(cmd == 2) CMD2();
        else if(cmd == 3) CMD3();
    }
}