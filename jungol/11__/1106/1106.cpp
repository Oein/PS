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

struct T{
    int x , y , cost;
};

int n , m , r , c , s , k;
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};
const int MAXN_M = 100 , INF = 987654321;
int visited[MAXN_M + 5][MAXN_M + 5];

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> r >> c >> s >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= n;j++){
            visited[i][j] = INF;
        }
    }

    queue<T> q;
    q.push({r , c , 0});
    visited[r][c] = 0;
    while(!q.empty()){
        T t = q.front();
        q.pop();
        if(t.x == s && t.y == k){
            cout << t.cost << endl;
            return 0;
        }

        for(int i = 0;i < 8;i++){
            int nx = t.x + dx[i] , ny = t.y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(visited[nx][ny] > t.cost + 1){
                visited[nx][ny] = t.cost + 1;
                q.push({nx , ny , t.cost + 1});
            }
        }
    }
}