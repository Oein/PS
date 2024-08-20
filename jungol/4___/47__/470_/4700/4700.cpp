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
    int n , m;
    cin >> n >> m;
    vector<int> vec(n , m);
    char x;
    cin >> x;
    while(x != 'e'){
        switch (x)
        {
        case 'i':
            int g;
            cin >> g;
            vec.push_back(g);
            break;
        case 'r':
            if(vec.size()) vec.pop_back();
            break;
        case 's':
            sort(vec.begin() , vec.end());
            break;
        case 't':
            if(vec.size()) swap(vec[0] , vec[vec.size() - 1]);
            break;
        default:
            break;
        }

        cin >> x;
    }


    for(auto x : vec) cout << x << " ";
}