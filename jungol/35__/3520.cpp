#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int , int> pi_i;

struct Student{
    string name;
    int like_percent;
    int idx;
    bool operator < (const Student& rhs) const{
        if(like_percent == rhs.like_percent) {
            if(name == rhs.name) return idx < rhs.idx;
            else return name < rhs.name;
        }
        return like_percent > rhs.like_percent;
    }
};

int n , q;
Student a[100005];

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 0;i < n;i++){
        cin >> a[i].name >> a[i].like_percent;
        a[i].idx = i + 1;
    }
    sort(a , a + n);
    for(int i = 0;i < q;i++){
        int id;
        cin >> id;
        id--;
        cout << a[id].idx << " ";
    }
}