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
typedef pair<pair<int , int> , pair<int , int>> ppi_i__pi_i;
typedef pair<long long , long long> pll_ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> ms_i;
typedef map<string , string> ms_s;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

const int maxN = 55;
int n; // 3 ~ 50

struct x_line {
    int x;
    int yDown;
    int idx;

    bool operator<(const x_line& other) const {
        return yDown > other.yDown;
    }
};

vector<x_line> v;
vector<pi_i> ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i = 1;i < n;i++){
        int inp , idx = 0;
        cin >> inp;
        if(inp != 0) {
            v.push_back({i , inp , idx});
            idx++;
        }
        int lastDid = -1;
        for(;inp != 0;){
            
            cin >> inp;
            if(inp != 0) {
                v.push_back({i , inp , idx});
                idx++;
            }
        }
    }

    sort(v.begin(), v.end()); // 높이에 따라 정렬

    vector<int> oton(n + 5); 
	for(int i = 0;i <= n;i++){
        oton[i] = i;
    }

    for (auto id : v) {
		swap(oton[id.x], oton[id.x + 1]); 
	}

    /*
        ? ? ? ? ? (이상한 순서)

            ->

        1 2 3 4 5 (정렬됨)

        이렇게 바꿔주면 됨

        swap 으로 하는 정렬 있음
        씃 **이름은 모름**
    */

   reverse(v.begin(), v.end()); // 아래에서 위로 올라가며 정렬 해야됨

    for (auto id : v) {
		if (oton[id.x] > oton[id.x + 1]) {
			swap(oton[id.x], oton[id.x + 1]); 
			ans.push_back({ id.x , id.idx });
		}
	}

   cout << ans.size() << "\n";
    for(auto id : ans){
        cout << id.first << " " << id.second + 1 << "\n";
    }
}