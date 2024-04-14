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
    string a , b;
    cin >> a >> b;
    for(int i = 0;i < min(a.size() , b.size());i++){
        int aNum = a[a.size() - i - 1] - '0';
        int bNum = b[b.size() - i - 1] - '0';
        if(aNum + bNum > 9) {
            cout << "NO";
            return 0;
        }   
    }

    cout << "YES";
    return 0;
}