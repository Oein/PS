#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt;
    cin >> cnt;
    string str;
    set<char> c[55];
    for(int i = 0;i < cnt;i++) {
        cin >> str;
        for(int j = 0;j < str.size();j++)
            c[j].insert(str[j]);
    }
    for(int j = 0;j < str.size();j++) {
        if(c[j].size() == 1) {
            for(auto x : c[j]) cout << x;
        } else cout << "?";
    }
}

