#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int x;
vector<int> v; // 숫자들
vector<int> maked_number;
vector<bool> is_used; // idx로 숫자 구별

void get(int cnt , int luni) {
    if (cnt == 6) {

        for(auto x : maked_number){
            cout << x << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = luni; i < v.size(); i++) {
        if (!is_used[i]) {
            is_used[i] = true;
            maked_number.push_back(v[i]);

            get(cnt + 1 , i);

            is_used[i] = false;
            maked_number.pop_back();
        }
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (true) {
        while (v.size()) {
            v.pop_back();
        }
        while (is_used.size()) {
            is_used.pop_back();
        }

        int x;
        cin >> x;
        if(x == 0){
            return 0;
        }else{
            for(int i = 0;i < x;i++){
                is_used.push_back(false);
                int jjj = 0;
                cin >> jjj;
                v.push_back(jjj);
            }
            
            sort(v.begin() , v.end());
            
            get(0 , 0);
            cout << "\n";
            
        }
    }
}
