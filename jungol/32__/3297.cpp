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

int n , m;
int arr[1000000];
ll tree[1000000 * 4];

void build (int now, int s, int e){
    if (s == e){ 
        tree[now] = arr[s];
        return;
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    build(lch, s, m);
    build(rch, m + 1, e);
    tree[now] = tree[lch] + tree[rch];
}

void update(int now, int s, int e, int tgIdx, int val){
    if (s == e){
        tree[now] = val;
        return;
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    if ( tgIdx <= m) update(lch, s, m, tgIdx, val );
    else update(rch, m + 1, e, tgIdx, val );
    tree[now] = tree[lch] + tree[rch];
}

ll query(int now, int s, int e, int fs, int fe){
    if (e < fs || fe < s) {
        return 0;
    }
    if (fs <= s && e <= fe) {
        return tree[now];
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    ll left = query(lch, s, m, fs, fe);
    ll right = query(rch, m + 1, e, fs, fe);
    return left + right;
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> arr[i];
    }
    build(1 , 1 , n);
    cin >> m;
    for(int i = 0;i < m;i++) {
        int cmd;
        cin >> cmd;
        if(cmd == 1) {
            int a;
            cin >> a >> arr[a];
            update(1 , 1 , n , a , arr[a]);
        }
        if(cmd == 2) {
            int s , e;
            cin >> s >> e;
            cout << query(1 , 1 , n , s , e) << "\n";
        }
    }
}