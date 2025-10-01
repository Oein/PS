#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

int n;
int wo[25] , woc;

int findLCost(int woidx , int oa , int ob){
    if(woidx >= woc) {
        return 0;
    }

    int nowo = wo[woidx];
    int tc1 = abs(oa - nowo) + findLCost(woidx + 1 , nowo , ob); // 왼쪽으로 밀기
    int tc2 = abs(ob - nowo) + findLCost(woidx + 1 , oa , nowo); // 오른쪽으로

    return min(tc1 , tc2);
}

int main(){
    cin.tie(0); cout.tie(0);
    int oa , ob;
    cin >> n >> oa >> ob >> woc;
    for(int i = 0;i < woc;i++) cin >> wo[i];
    cout << findLCost(0 , oa , ob);
}
