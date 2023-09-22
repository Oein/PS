#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <climits>

using namespace std;

typedef long long ll;

int t,n,a,b,ix=INT_MAX,iy=INT_MAX,ax=INT_MIN,ay=INT_MIN;

struct Node{
    long long x , y;
    
    bool operator < (const Node &b) const {
        return (x != b.x) ? (x < b.x) : (y < b.y);
    }

    bool operator == (const Node &b) const {
        return (x == b.x) && (y == b.y);
    }
};

vector<Node> nodes;

// ---------------- Do ---------------
bool can(int square_cnt, vector<Node> arr, ll len)
{
    // ---------------- End Staindment ---------------
    if (square_cnt == 4) {
        if (arr.size() == 0) return true;
        else return false;
    }
    if (arr.size() == 0) return true;

    // --------------- Get M[in/ax] point ---------------
    ll minx = INT_MAX, miny = INT_MAX;
    ll maxx = INT_MIN, maxy = INT_MIN;
    
    for (int i = 0; i < arr.size(); i++) {
        minx = min(minx, arr[i].x);
        miny = min(miny, arr[i].y);
        maxx = max(maxx, arr[i].x);
        maxy = max(maxy, arr[i].y);
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i].x -= minx;
        arr[i].y -= miny;
    }
    maxx -= minx;
    maxy -= miny;
    
    // --------------- Do ---------------
    vector<Node> tmp;
    // Left Down (그 네모에서 Left Down)
    for (int i = 0; i < arr.size(); i++) {
        if (!(arr[i].x <= len && arr[i].y <= len)) {
            tmp.push_back(arr[i]);
        }
    }
    if (can(square_cnt + 1, tmp, len)) return true;
    tmp.clear();

    // Left Up
    for (int i = 0; i < arr.size(); i++) {
        if (!(arr[i].x <= len && arr[i].y >= maxy - len)) {
            tmp.push_back(arr[i]);
        }
    }
    if (can(square_cnt + 1, tmp, len)) return true;
    tmp.clear();

    // RIght down
    for (int i = 0; i < arr.size(); i++) {
        if (!(arr[i].x >= maxx - len && arr[i].y <= len)) {
            tmp.push_back(arr[i]);
        }
    }
    if (can(square_cnt + 1, tmp, len)) return true;
    tmp.clear();

    // Right Up
    for (int i = 0; i < arr.size(); i++) {
        if (!(arr[i].x >= maxx - len && arr[i].y >= maxy - len)) {
            tmp.push_back(arr[i]);
        }
    }
    if (can(square_cnt + 1, tmp, len)) return true;
    tmp.clear();
    
    // 이중에 아무거나 있으면 가능 한거니까

    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        // --------------- init  -------------
        nodes.clear();
        ix=INT_MAX;
        iy=INT_MAX;
        ax=INT_MIN;
        ay=INT_MIN;
        // --------------- input -------------
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> a >> b;
            nodes.push_back({a,b});
            ix = min(ix , a);
            iy = min(iy , b);
            ax = max(ax , a);
            ay = max(ay , b);
        }
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i].x -= ix;
            nodes[i].y -= iy;
        }
        ax -= ix;
        ay -= iy;
        // -------------- Pre Do -------------
        sort(nodes.begin() , nodes.end());
        // ---------------- Do ---------------
        ll low = 0 , high = max(ax , ay) , mid,ans=-1;
        while(low <= high){
            mid = (low + high) / 2;
            if(can(1, nodes, mid)){
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
