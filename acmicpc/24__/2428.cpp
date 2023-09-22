#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll ans = 0;

vector<int> solutions;

ll find_sols(int idx){
    int r = idx - 1;
    int l = 0;
    while(l <= r){
        int mid = (l + r) / 2; // middle idx
        if(solutions[mid] < solutions[idx] * 0.9) l = mid + 1;
        else r = mid - 1;
    }
    
    return idx - l;
}

int main(){
    int n = 0;
    cin >> n;

    for(int i = 0; i < n;i++){
        int solution = 0;
        cin >> solution;
        solutions.push_back(solution);
    }
    
    sort(solutions.begin() , solutions.end());
    
    for(int i = 1;i < n;i++){
        ans += find_sols(i);
    }
    
    cout << ans;
}
