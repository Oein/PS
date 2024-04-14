#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <any>

using namespace std;

set<string> s;
set<string> s2;

int main() {
    int n;
    cin >> n;
    char lastEnd = ' ';
    char lastStart = ' ';
    bool e = false;
    bool gu = false;
    for(int i = 0;i < n;i++) {
        string str;
        cin >> str;
        s.insert(str);
        if(str == "?") {
            e = true;
            gu = true;
            continue;
        }
        if(e) {
            lastStart = str[0];
            e = false;
            continue;
        }
        if(!gu)
            lastEnd = str[str.size() - 1];
    }
    
    int x;
    cin >> x;
    for(int i = 0;i < x;i++) {
        string str;
        cin >> str;
        if(s.find(str) != s.end()) continue;
        if(lastEnd != ' ' && str[0] != lastEnd) continue;
        if(lastStart != ' ' && str[str.size() - 1] != lastStart) continue;
        cout << str;
        return 0;
    }
    
    // cout << lastEnd << " ? " << lastStart;
}
