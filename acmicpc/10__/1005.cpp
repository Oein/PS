#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> paths[1001];
int delay[1001] , indeg[1001];
int t , n , k , w , x , y;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;

        for(int i = 1; i <= n;i++){
            paths[i].clear();
        }
        memset(indeg , 0 , sizeof(indeg));

        // get delays to build
        for(int i = 1;i <= n;i++){
            cin >> delay[i];
        }

        // get 우선순위
        for(int i = 1;i <= k;i++){
            cin >> x >> y;
            // x first , y second
            indeg[y]++;
            paths[x].push_back(y);
        }

        cin >> w;

        int nTime[1001] = {0,};
        queue<int> q;
        for(int i = 1;i <= n;i++){
            if(indeg[i] == 0)
            {
                nTime[i] = delay[i];
                q.push(i);
            } 
        }

        // loop in q
        while (!q.empty())
        {
            int now_ = q.front();
            q.pop();
            if(now_ == w)
                break;
            for(int next_ : paths[now_]){
                nTime[next_] = max(nTime[next_] , nTime[now_] + delay[next_]);
                if(--indeg[next_] == 0){
                    q.push(next_);
                }
            }
        }

        // print ans
        cout << nTime[w] << "\n";
    }
}