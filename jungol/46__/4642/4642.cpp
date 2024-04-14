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

struct Student{
    string name;
    int score;

    bool operator < (const Student& rhs) const{
        if(score == rhs.score) return strcmp(name.c_str() , rhs.name.c_str()) < 0;
        return score > rhs.score;
    }
};

int n;
Student a[50005];

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i].name >> a[i].score;
    }

    sort(a , a + n);

    for(int i = 0;i < n;i++){
        cout << a[i].name << " " << a[i].score << "\n";
    }
}