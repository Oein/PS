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
typedef pair<pair<int , int> , pair<int , int>> ppi_i__pi_i;
typedef pair<long long , long long> pll_ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> ms_i;
typedef map<string , string> ms_s;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

#define MAXSIZE 255

int l , w , n , k , inX , inY , sum[MAXSIZE][MAXSIZE] = {0,};
// 가로 길이
// 세로 길이
// 전체 개수
// 한 네모 안에 들어와야 하는 꽃의 개수
// x , y 까지 꽃 개수 [sum[x][y]]
vector<pi_i> roses;

int getBorder(int x1 , int x2 , int y1 , int y2){
    return (x2 - x1 + 1) * 2 + (y2 - y1 + 1) * 2;
}

int roseCount(int stx , int sty , int edx , int edy){
    int x1 = stx;
    int y1 = sty;
    int x2 = edx;
    int y2 = edy;

    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int NemosUp[MAXSIZE];
int NemosDown[MAXSIZE];
int NemosLeft[MAXSIZE];
int NemosRight[MAXSIZE];

#define INFINITY 9999999

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    fill(NemosUp , NemosUp + MAXSIZE , INFINITY);
    fill(NemosDown , NemosDown + MAXSIZE , INFINITY);
    fill(NemosLeft , NemosLeft + MAXSIZE , INFINITY);
    fill(NemosRight , NemosRight + MAXSIZE , INFINITY);

    cin >> l >> w >> n >> k;

    for(int i = 0;i < n;i++){
        cin >> inX >> inY;
        sum[inX][inY]++;
    }

    // ************************* Get rose count *************************
    for(int i = 1;i <= w;i++){ // w * l
        for(int j = 1;j <= l;j++){
            sum[j][i] = sum[j - 1][i] + sum[j][i - 1] + sum[j][i] - sum[j - 1][i - 1];
        }
    }
    
    // ************************* Calc *************************
    
    for(int downY = 1;downY <= w;downY++){
        for(int upY = downY;upY <= w;upY++){
            int leftX = 1;
            int rightX = 1;
            int rc = 0;
            while(leftX <= l && rightX <= l){
                rc = roseCount(leftX , downY , rightX , upY);
                if(rc == k){
                    int border = getBorder(leftX , rightX , downY , upY);
                    NemosUp[upY] = min(NemosUp[upY] , border);
                    NemosDown[downY] = min(NemosDown[downY] , border);
                    NemosLeft[leftX] = min(NemosLeft[leftX] , border);
                    NemosRight[rightX] = min(NemosRight[rightX] , border);
                }

                if(rc >= k){
                    leftX++;
                }
                else {
                    rightX++;
                }
            }
        }
    }

    // ************************* Min *************************

    int minBorder = INFINITY;

    for(int i = 2;i <= w;i++) NemosUp[i] = min(NemosUp[i] , NemosUp[i - 1]);
    for(int i = w - 1;i >= 1;i--) NemosDown[i] = min(NemosDown[i] , NemosDown[i + 1]);

    for(int i = 2;i <= l;i++) NemosRight[i] = min(NemosRight[i] , NemosRight[i - 1]);
    for(int i = l - 1;i >= 1;i--) NemosLeft[i] = min(NemosLeft[i] , NemosLeft[i + 1]);
    

    // 가로줄로 나누기
    for(int i = 1;i < w;i++){
        minBorder = min(minBorder , NemosUp[i] + NemosDown[i + 1]);
    }

    // 세로줄로 나누기
    for(int i = 1;i < l;i++){
        minBorder = min(minBorder , NemosRight[i] + NemosLeft[i + 1]);
    }

    if(minBorder >= INFINITY) cout << "NO";
    else cout << minBorder;
}