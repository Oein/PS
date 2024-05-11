#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Human{
    int h = 0;
    int o = 0;
};

int main(){
    int count = 0;
    int d = 0;

    cin >> count;

    vector<Human> humans;

    for(int i  = 0;i < count;i++){
        int h = 0;
        int o = 0;
        cin >> h >> o;

        if(h > o){ //swap
            int c = h;
            h = o;
            o = c;
        }
        Human humman;
        humman.h = h;
        humman.o = o;
        humans.push_back(humman);
    }

    cin >> d;

    vector<int> Rhumans;
    vector<int> Rhumans_back;

    for(int i = 0;i < count;i++){
        if(humans[i].o - humans[i].h <= d){
            Rhumans.push_back(humans[i].h);
            Rhumans_back.push_back(humans[i].o);
        }
    }

    int m = 0;

    humans.clear();

    sort(Rhumans.begin() , Rhumans.end());
    sort(Rhumans_back.begin() , Rhumans_back.end());

    int mx = 0;

    for(int i = 0;i < Rhumans.size();i++){
        int upper_bounded = upper_bound(Rhumans_back.begin() , Rhumans_back.end() , Rhumans[i] + d) - Rhumans_back.begin();
        mx = max(mx , upper_bounded - i);
    }

    cout << mx;
}