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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    int front_leg_count = 0;
    for(int i = 0;i < s.size() - 1;i++){
        if(s[i] == '(' && s[i + 1] == '('){
            // 앞다리
            front_leg_count++;
        }

        if(s[i] == ')' && s[i + 1] == ')'){
            // 뒷다리
            ans += front_leg_count;
        }
    }
    cout << ans;
}