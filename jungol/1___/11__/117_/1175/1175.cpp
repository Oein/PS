#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int n , m;
vector<int> nums;

void roll(int step , int added){
    if(step >= n){
        if(added == m){
            for(auto i :nums){
                cout << i << " ";
            }
            cout << "\n";
        }
        return;
    }

    // roll it
    for(int i = 1;i <= 6;i++){
        if(added + i > m) {
            continue;
        }
        nums.push_back(i);
        roll(step +1 , added + i);
        nums.pop_back();
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    roll(0 , 0);
}
