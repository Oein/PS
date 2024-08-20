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
typedef pair<pair<int , int> , pair<int , int>> ppi_i__pi_i;
typedef pair<long long , long long> pll_ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> ms_i;
typedef map<string , string> ms_s;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

#define MAX 500005

int n , a , b;
string str;
int start[MAX];
int word_len[MAX];

int sol(int len){
    int ret = 0;
    for (int i = 0; i < n; i = (i + len < n ? start[i + len] : n)) {
        ret += word_len[i] + 1;
    }
    return ret - 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    getline(cin , str);

    str += " ";
    n = str.size() - 1;

    int word_start = 0;
    for (int i = 0; i <= n; ++i) {
        if (str[i] == ' ') {
            word_len[word_start] = i - word_start;
            word_start = i + 1;
        }
        start[i] = word_start;
    }

    cin >> a >> b;
    for(int i = a;i <= b;i++){
        cout << sol(i) << "\n";
    }
}