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

int main(){
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> vvi;
    for(int i = 0;i < n;i++){
        int g;
        cin >> g;
        vector<int> vi;
        for(int j = 0;j < g;j++) {
            int x;
            cin >> x;
            vi.push_back(x);
        }
        vvi.push_back(vi);
    }

    for(int i = 0;i < n;i++){
        int g;
        cin >> g;
        for(auto x : vvi[g]) cout << x << " ";
        cout << "\n";
    }
}