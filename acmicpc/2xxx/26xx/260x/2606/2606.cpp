#include <bits/stdc++.h>
using namespace std;

set<int> is_visited;
vector<vector<int>> childrenByIndex;

void bfs(int start){
    queue<int> queue;
    
    queue.push(start);
    
    while (!queue.empty()) {
        if(is_visited.find(queue.front()) != is_visited.end()){ //갔던곳이면
            queue.pop();
            continue;
        }
        
        is_visited.insert(queue.front());
        
        for(int i = 0;i < childrenByIndex[queue.front()].size();i++){
            int data = childrenByIndex[queue.front()][i];
            if(is_visited.find(data) == is_visited.end()){
                queue.push(data);
            }
        }
        
        queue.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int computers = 0;
    int edges = 0;
    
    cin >> computers >> edges;
    
    for(int i = 0;i <= computers;i++){
        vector<int> children;
        childrenByIndex.push_back(children);
    }
    
    for(int i = 0;i < edges;i++){
        int from = 0;
        int to = 0;
        cin >> from >> to;
        
        childrenByIndex[from].push_back(to);
        childrenByIndex[to].push_back(from);
    }
    
    for(int i = 0;i < computers;i++){
        sort(childrenByIndex[i].begin() , childrenByIndex[i].end());
    }
    
    bfs(1);
    
    int yesViruis = 0;
    for(int i = 0;i <= computers;i++){
        if(is_visited.find(i) != is_visited.end()){
            //갔던 곳이면
            yesViruis++;
        }
    }
    
    cout << yesViruis - 1 << "\n";
}
