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

struct Rec{
    int w , h;
    bool operator < (const Rec& rhs) const{
        return w * h < rhs.w * rhs.h;
    }
};

int main(){
    cin.tie(0); cout.tie(0);
    Rec a , b;
    cin >> a.w >> a.h >> b.w >> b.h;
    if(a < b) cout << "a is smaller\n";
    else cout << "b is smaller\n";
}