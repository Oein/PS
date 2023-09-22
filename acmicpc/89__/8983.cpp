#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int abs(int x) { return x < 0 ? x * -1 : x; }

int main(){
    int count_of_guns = 0;
    int count_of_animals = 0;
    int limit_of_guns = 0;

    vector<ll> x_of_guns;

    cin >> count_of_guns >> count_of_animals >> limit_of_guns;

    for(int i = 0;i < count_of_guns;i++){
        ll x_pos = 0;
        cin >> x_pos;
        x_of_guns.push_back(x_pos);
    }

    int dead_animals = 0;

    for(int i = 0;i < count_of_animals;i++){
        ll x_pos = 0;
        ll y_pos = 0;

        cin >> x_pos >> y_pos;

        int j = 0;
        bool can_kill = false;
        while(j < count_of_guns){
            if(abs(x_of_guns[j]-x_pos) + y_pos <= limit_of_guns){
                can_kill = true;
                break;
            }
            j++;
        }
        if(can_kill) dead_animals++;
    }

    cout << dead_animals;
}