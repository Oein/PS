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

const int modV = 20091024;

unsigned long long fast_pow(long long under , long long top){
    unsigned long long res = 1;
    while(top){
        if(top & 1)res = (res * under) % modV;
        under = (under * under) % modV;
        top >>= 1;
    }
    return res % modV;
}

int main(){
    cin.tie(0); cout.tie(0);
    long long x , y;

    cin >> x >> y;
    cout << fast_pow(x , y) << "\n";
}