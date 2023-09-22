#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<pair<int , int> , pair<int , int>> ppiipii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> msi;
typedef map<string , string> mss;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;
#define loopO(x, n) for(int x=1;x<=n;x++)
#define loopZ(x, n) for(int x=0;x<n;x++)

bool arr[105];
int cnt = 0 , n;

void setTrue(int mult){
    for(int i = mult;i <= n;i += mult * 2){
        if(!arr[i]) cnt--;
        arr[i] = true;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    cnt = n;
    
    int mult = 1;
    while(cnt > 1){
        setTrue(mult);
        mult *= 2;
    }
    
    for(int i = 1;i <= n;i++){
        if(!arr[i]) {
            cout << i;
            return 0;
        }
    }
}


