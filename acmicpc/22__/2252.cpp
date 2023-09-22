#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX 100010

using namespace std;

int inputed_count[MAX];
// if inputed_count[?] == 0 , ? is starting point , 그러니까 원천이라는 소리
vector<int> node[MAX];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n = 0 , m = 0;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a , b;
        cin >> a >> b;
        
        // graph ( b -> a )
        inputed_count[b]++;
        node[a].push_back(b);
    }
    
    queue<int> q;
    for(int i = 1; i <= n;i++){
        if(inputed_count[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        cout << now << " ";
        
        for (int i = 0; i < node[now].size(); i++)
        {
            int next = node[now][i];
            inputed_count[next]--;
 
            if (inputed_count[next] == 0) q.push(next);
        }
    }
}
