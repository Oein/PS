#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int n,k,x,y,x2,y2,wid;
const int MAX = 40000 + 2;

vector<int> hole;
int depth[MAX];
int byebyeWater[MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;

    // [INPUT] line's x , y
    cin >> x >> y; // always 0 , 0
    for(int i = 0; i < n / 2 - 1 ; i++ ){
        cin >> x >> y >> x2 >> y2; // get x , y
        for (int j = x; j < x2; j++) {
            depth[j] = y;
        }
    }
    cin >> wid >> y; // end of point , y is always 0


    // [INPUT] hole's x , y
    cin >> k;
    for(int i = 0;i < k;i++){
        cin >> x >> y >> x2 >> y2;
        hole.push_back(x);
    }

    // [GET] byebyeWater
    for(int i = 0; i < hole.size(); i++){
        int hole_x = hole[i] , min_higeht = depth[hole_x];

        byebyeWater[hole_x] = min_higeht;

        // [GET] Left
        for(int j = hole_x - 1; j >= 0; j--){
            min_higeht = min(min_higeht , depth[j]);
            byebyeWater[j] = max(min_higeht , byebyeWater[j]);
        }

        min_higeht = depth[hole_x];

        // [GET] Right
        for(int j = hole_x + 1; j < wid; j++){
            min_higeht = min(min_higeht , depth[j]);
            byebyeWater[j] = max(min_higeht , byebyeWater[j]);
        }
    }

    // [GET] result
    int result = 0;
    for(int i = 0;i < wid;i++){
        result += depth[i] - byebyeWater[i];
    }

    // [OUTPUT] result
    cout << result << "\n";
}