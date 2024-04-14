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
typedef pair<int , int> pii;
typedef pair<pair<int , int> , pair<int , int>> ppiipii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> msi;
typedef map<string , string> mss;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

struct Node{
    int x,y;
};
queue<Node> q;

int n , m;
int monun_paper[101][101];
//               y    x
bool outside_air[101][101];
//               y    x
bool melt_it[101][101];
//            y    x

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

bool allNone(){
    for(int i = 0;i < n; i++){
        for(int j = 0;j < m;j++){
            if(monun_paper[i][j]) return false;
        }
    }
    return true;
}

void getIsThisPlaceIsOutSide(){
    q.push({0 , 0});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(monun_paper[nx][ny]) continue;
            if(outside_air[nx][ny]) continue;
            outside_air[nx][ny] = true;
            q.push({nx , ny});
        }
    }
}

void getCanIMeltHere(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(monun_paper[i][j] == 1) q.push({i,j});
        }
    }

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        int outside_count = 0;
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(outside_air[nx][ny]) outside_count++;
        }

        if(outside_count >= 2) melt_it[x][y] = 1;
    }
}


void meltThem(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(melt_it[i][j]) monun_paper[i][j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int ans = 0;
    for(int i = 0;i < n; i++){
        for(int j = 0;j < m;j++){
            cin >> monun_paper[i][j];
        }
    }

    while(1){
        if(allNone() == true) break;
        memset(outside_air, 0, sizeof(outside_air));
        memset(melt_it, 0, sizeof(melt_it));
        getIsThisPlaceIsOutSide();
        getCanIMeltHere();
        meltThem();
        ans++;
    }

    cout << ans;
}