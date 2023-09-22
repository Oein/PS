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

int n , m;
int stY , stX , edY , edX;
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};
bool visited[1005][1005];

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> stY >> stX >> edY >> edX;
    queue<pair<pair<int , int> , int>> q;
    q.push({{stY , stX} , 0});
    visited[stY][stX] = true;

    while(!q.empty()){
        int nowX = q.front().first.second;
        int nowY = q.front().first.first;
        int ti = q.front().second + 1;
        if(nowX == edX && nowY == edY){
            cout << q.front().second;
            return 0;
        }
        q.pop();

        for(int i = 0;i < 8;i++){
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];
            if(nx <= 0 || nx > m || ny <= 0 || ny > n) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({{ny , nx} , ti});
        }
    }
}