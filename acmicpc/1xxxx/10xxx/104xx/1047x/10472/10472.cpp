//
//  main.cpp
//  c++
//
//  Created by Oein on 1/6/22.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> cng[9] = {
    {0, 1, 3}, {0, 1, 2, 4}, {1,2, 5},
    {0, 3, 4, 6}, {1, 3,4, 5, 7}, {2, 4, 5, 8},
    {3, 6, 7}, {4, 6,7, 8}, {5, 7,8}
};

int bfs(string s) {
    queue<string> q;
    set<string> check;
    q.push("000000000");
    check.insert("000000000");
    int time = 1;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            string here = q.front();
            q.pop();
            for (int i = 0; i < 9; i++) {
                string next = here;
                for (int j = 0; j < cng[i].size(); j++) {
                    if (next[cng[i][j]] == '1') {
                        next[cng[i][j]] = '0';
                    }
                    else {
                        next[cng[i][j]] = '1';
                    }
                }
                if (check.find(next) != check.end()) continue;
                if (s == next) return time;
                q.push(next);
                check.insert(next);
            }
        }
        time++;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t = 0;
    cin >> t;
    for(int tmptmptmp = 0;tmptmptmp < t;tmptmptmp++){
        string map = "";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char ch;
                cin >> ch;
                if (ch == '*') {
                    map += "1";
                }
                else {
                    map += "0";
                }
            }
            getchar(); // \n
        }
        if (map == "000000000") cout << "0\n";
        else{
            cout << bfs(map) << "\n";
        }
    }
}
