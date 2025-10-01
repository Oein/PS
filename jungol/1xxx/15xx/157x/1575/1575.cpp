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
struct MAX{
    int arr[50005];
    int tree[50005 * 4];
    int etd = -1;

    inline int Max(int a, int b){ return a > b ? a : b; } 
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
        return Max(left, right);
    }
};

struct MIN{
    int arr[50005];
    int tree[50005 * 4];
    int etd = 1000001;

    inline int Max(int a, int b){ return a < b ? a : b; } 
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
        return Max(left, right);
    }
};

MAX ax;
MIN in;

int main(){
    cin.tie(0); cout.tie(0);

    int n , q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        ax.arr[i] = x;
        in.arr[i] = x;
    }

    ax.build(1 , 1 , n);
    in.build(1 , 1 , n);

    for(int i = 1;i <= q;i++) {
        int s , e;
        cin >> s >> e;
        cout << ax.query(1 , 1 , n , s , e) - in.query(1 , 1 , n , s , e) << "\n";
    }
}