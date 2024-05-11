#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

struct ty{
    int x;
    int y;
    int bandae_x;
    int uod;
};
              //   x    y       반대쪽  UoD

bool cmp(ty a, ty b) {
    if (a.x == b.x) {
        if (b.y == a.y) {
            return a.uod < b.uod;
        }
        return a.y > b.y;
    }
    return a.x < b.x;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<ty> vc;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vc.push_back({a , b , c , i});
        vc.push_back({c , b , a , i});
    }

    sort(vc.begin(), vc.end() , cmp);

    map<pair<pair<int, int> , int>, int, greater< pair<pair<int, int> , int > > > mp;
        //   h    x    bandae  sortUtoD

    int lmh = -1;
    map<int, int, less< int > > mp2;
    mp[{{0 , 0} , 0}] = 0; // Error 방지

    //cout << "\tX\tY\tBandae\tisDown\tindex\tlmh\n";

    for (int i = 0; i < vc.size(); i++) {
        int now_x = vc[i].x;
        int now_y = vc[i].y;
        int bandae_x = vc[i].bandae_x;
        int isDown = (bandae_x > now_x) ? 0 : 1;
        //cout << "State\t" << now_x << "\t" << now_y << "\t" << bandae_x << "\t" << isDown << "\t" << i << "\t" << lmh;
        //cout << "\n";

        if (isDown == 0) { // 올라감
            if(mp.find({{now_y , now_x} , vc[i].uod}) == mp.end()) mp[{{now_y , now_x} , vc[i].uod}] = 1;
            else mp[{{now_y , now_x} , vc[i].uod}]++;
        }
        else {             // 내려감
            if(mp[{{now_y , bandae_x} , vc[i].uod}] == 1) mp.erase({{now_y , bandae_x} , vc[i].uod});
            else mp[{{now_y , bandae_x} , vc[i].uod}]--;
        }

        auto it = mp.begin(); // heighest
        auto mh = it->first.first.first;

        if (lmh != mh) {
            lmh = mh; // 최고 높이에 변화가 생김
            if (mp2.find(now_x) == mp2.end()) {
                mp2[now_x] = mh;
            }
            else {
                if(isDown)
                    mp2[now_x] = min(mh, mp2[now_x]);
                else
                    mp2[now_x] = max(mh, mp2[now_x]);
            }
        }
    }

    for (auto itx : mp2) {
        cout << itx.first << " " << itx.second << " ";
    }
}
