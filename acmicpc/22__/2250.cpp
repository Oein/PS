#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
    int left = -1;
    int right = -1;
};

#define MAX_NODE_COUNT 10005

Node nodes[MAX_NODE_COUNT];
int low[MAX_NODE_COUNT];
int high[MAX_NODE_COUNT];
int arr_for_check_root[MAX_NODE_COUNT];

int whereAmI = 1;
void dfs(int now , int lev){
    if(nodes[now].left > 0) dfs(nodes[now].left , lev + 1);
    low[lev] = min(low[lev] , whereAmI);
    high[lev] = max(high[lev] , whereAmI);
    whereAmI++;
    if(nodes[now].right > 0) dfs(nodes[now].right , lev + 1);
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        low[i] = 987654321;
        
        int par , ch1 , ch2;
        cin >> par >> ch1 >> ch2;
        nodes[par] = {ch1 , ch2};
        
        arr_for_check_root[par]++;
        
        if(ch1 > 0){
            arr_for_check_root[ch1]++;
        }
        
        if(ch2 > 0){
            arr_for_check_root[ch2]++;
        }
    }
    
    int root = 0;
    for(int i = 1; i <= n; i++){
        if(arr_for_check_root[i] == 1) root = i;
    }
    
    dfs(root , 1);
    
    int ans = high[1] - low[1] + 1;
    int anl = 1;
    
    for(int i = 2; i <= n;i++){
        int tmp = high[i] - low[i] + 1;
        if(tmp > ans){
            ans = tmp;
            anl = i;
        }
    }
    
    cout << anl << " " << ans;
}
