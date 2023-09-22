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
typedef pair<int , int> pii;

const int limit_div = 10000;

/*
Fibo : 1 1 2 3 5 8 13

1 1 & 1 1 > 2 1
1 0 & 1 0 > 1 1

2 1 & 1 1 > 3 2
1 1 & 1 0 > 2 1

3 2 & 1 1 > 5 3
2 1 & 1 0 > 3 2
*/

struct twoBtwo{
public:
    int leftTop;
    int rightTop;
    int leftBottom;
    int rightBottom;
    
public:
    void limitB(int l) {
        this->leftTop %= l;
        this->rightTop %= l;
        this->leftBottom %= l;
        this->rightBottom %= l;
    }

    twoBtwo operator* (const twoBtwo &a) const {
        twoBtwo ans;
        ans.leftTop =
            this->leftTop * a.leftTop +
            this->rightTop * a.leftBottom;
        ans.rightTop =
            this->leftTop * a.rightTop +
            this->rightTop * a.rightBottom;
        ans.leftBottom =
            this->leftBottom * a.leftTop +
            this->rightBottom * a.leftBottom;
        ans.rightBottom =
            this->leftBottom * a.rightTop +
            this->rightBottom * a.rightBottom;
        
        ans.limitB(limit_div);

        return ans;
    }
};

twoBtwo y = {1 , 1 , 1 , 0};
twoBtwo x = {1 , 1 , 1 , 0};

twoBtwo solve(int n) {
    // cout << "REQ : " << n << "\n";
    if(n == 0) return y;
    if(n == 1) return x;
    twoBtwo below = solve(n / 2);
    if(n % 2) return below * below * x;
    return below * below;
}

int main(){
    cin.tie(0); cout.tie(0);
    while(1) {
        int n;
        cin >> n;
        if(n == -1) return 0;
        if(n == 0) {
            cout << "0\n";
            continue;
            
        }
        twoBtwo d = solve(n);
        cout << d.rightTop % 10000 << "\n";
    }
}
