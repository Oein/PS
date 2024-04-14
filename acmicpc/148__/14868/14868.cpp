#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n , k , ans;
int fstk;
int board[2010][2010];
int union_arr[100010];
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
bool print_map = false;

queue< pair<int , int> > q;
queue< pair<int , int> > qq;

// union::find function
int find(int x){
    if(union_arr[x] == x) return x;
    return union_arr[x] = find(union_arr[x]);
}

// union::union function
void union_func(int x , int y){
    int x_root = find(x);
    int y_root = find(y);
    if(x_root == y_root) return;
    union_arr[x_root] = y_root;
}

// union::check function
bool check(int x , int y){
    return find(x) == find(y);
}

// spread function
void spread(){
    int sps = q.size();
    while(sps--){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(board[nx][ny] == 0) {
                board[nx][ny] = board[x][y];
                q.push(make_pair(nx , ny));
            }
        }
    }
}

// mix function
void mix(){
    while(!qq.empty()){
        int x = qq.front().first;
        int y = qq.front().second;
        qq.pop();
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(board[nx][ny] == 0) continue;

            // there is another group
            if(!check(board[nx][ny] , board[x][y])){ // dif group
                union_func(board[nx][ny] , board[x][y]);
                k--;
            }
        }
    }
}

void print_board(){
    cout << "============== Board === Time : " << ans << "\n";
    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <= n; j++)
            cout << board[j][i] << " ";
        cout << "\n";
    }
    cout << "=================================\n\n\n";
}

void print_union(){
    cout << "============== Union ============\n";
    for(int i = 1 ; i <= fstk ; i++)
        cout << union_arr[i] << " ";
    cout << "\n";
    cout << "k == " << k << "\n";
    cout << "=================================\n\n\n";
}

void next_year(){
    qq = q;
    mix();

    if(k <= 1){
        cout << ans;
        return;
    }

    ans++;
    spread();

    if(print_map) print_board();
    if(print_map) print_union();
    
    next_year();
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    fstk = k;
    
    for(int i = 1;i <= k;i++){
        int x , y;
        cin >> x >> y;
        board[x][y] = i;
        union_arr[i] = i;
        q.push(make_pair(x , y));
    }

    if(print_map) cout << "INIT BOARD\n";
    if(print_map) print_board();
    if(print_map) cout << "\n\n\n";
    
    next_year();
}
