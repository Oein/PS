// main.cpp
#include <future>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <chrono>
#include <vector>
#include <sys/resource.h>
#include <sys/time.h>

// solution.cpp
#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <cstring>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <algorithm>

// using
using namespace std;

// typedef
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// direction
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

// config defines
#define TIMEOUT 1000LL
#define SOLUTION_FUNCTION main_

// Main

struct Pos {
    int x;
    int y;
};

struct QData {
    Pos p;
    int money;
};

struct QComp {
    bool operator() (const QData& a, const QData& b) const {
        return a.money > b.money;
    }
};

int n, sx, sy, ey, ex, crossPrice;
bool visited[55][55];
int board[55][55];
Pos from[55][55];


void main_()
{
    int placedRoadsCount;
    cin >> n >> sy >> sx >> ey >> ex >> crossPrice >> placedRoadsCount;
    
    
    // Initlize
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            visited[i][j] = 0;
    crossPrice--;
    visited[sy][sx] = 1;
    from[sy][sx] = {sx, sy};
    
    for(int i = 0;i < placedRoadsCount;i++) {
        int rotCount;
        cin >> rotCount;
        Pos last;
        cin >> last.y >> last.x;
        rotCount--;
        board[last.y][last.x] = 1;
        while (rotCount--) {
            int y, x;
            cin >> y >> x;
            
            if(last.x == x)
                // y 이동
                for(int j = min(y, last.y); j <= max(y, last.y); j++)
                    board[j][x] = crossPrice;
            else
                // x 이동
                for(int j = min(x, last.x); j <= max(x, last.x); j++)
                    board[y][j] = crossPrice;
            
            last.x = x;
            last.y = y;
            
        }
    }
    
    priority_queue<QData, vector<QData>, QComp> pq;
    
    pq.push({
        {sx, sy}, board[sy][sx] + 1
    });
    
    while(!pq.empty()) {
        QData qf = pq.top();
        pq.pop();
        
        if(qf.p.x == ex && qf.p.y == ey) {
            Pos now = qf.p;
            Pos back = from[now.y][now.x];
            
            stack<Pos> path;
            
            bool changingDir = 0;
            if(now.x != back.x) changingDir = 1;
            
            while (now.x != sx || now.y != sy) {
                bool ncng = 1;
                if(back.x != now.x)
                    ncng = 0;
                
                if(changingDir != ncng) path.push(now);
                
                changingDir = ncng;
                
                now = back;
                back = from[now.y][now.x];
            }
            
            cout << qf.money << "\n";
            cout << path.size() + 1 << " ";
            cout << sy << " " << sx << " ";
            
            while (!path.empty()) {
                cout << path.top().y << " " << path.top().x << " ";
                path.pop();
            }
            return ;
        }
        
        for(int i = 0;i < 4;i++) {
            QData nq = qf;
            nq.p.x += dx[i];
            nq.p.y += dy[i];
            nq.money += board[nq.p.y][nq.p.x] + 1;
            
            Pos p = nq.p;
            
            if(p.x < 1 || p.y < 1 || p.x > n || p.y > n) continue;
            if(visited[p.y][p.x]) continue;
            
            from[p.y][p.x] = {qf.p.x, qf.p.y};
            visited[p.y][p.x] = 1;
            
            pq.push(nq);
        }
    }
}

#ifdef ONLINE_JUDGE
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    main_();
    return 0;
}
#endif
