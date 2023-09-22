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

int n , q;
int arr[50005];
int tree[50005 * 2];

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
void buildTree(){
    build(1, 1, n); 
}

int query(int now, int s, int e, int fs, int fe){
    if (e < fs || fe < s) return 0;
    if (fs <= s && e <= fe) return tree[now];
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    int left = query(lch, s, m, fs, fe);
    int right = query(rch, m + 1, e, fs, fe);
    return max(left, right);
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n >> q;

    for(int i = 1;i <= n;i++) {
        cin >> arr[i];
    }

    buildTree();

    for(int i = 0;i < q;i++) {
        int s , e;
        cin >> s >> e;
        cout << query(1 , 1 , n , s , e) << "\n";
    }
}