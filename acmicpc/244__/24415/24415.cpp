// 미완성
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<pair<int , int> , pair<int , int>> ppiipii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> msi;
typedef map<string , string> mss;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

class Move {
public:
    vector<pii> dt;

    Move(int n=0){
        for(int i = 0;i < n;i++){
            this->dt.push_back({i , 0});
        }
    }

    Move(const vector<pii>& dt){
        this->dt = dt;
    }

    void swap(int a , int b){
        std::swap(this->dt[a] , this->dt[b]);
    }

    void add(int a , int b){
        this->dt[a].second = (this->dt[a].second + b) % 26;
    }

    string apply(const string& str){
        string res = str;
        for(int i = 0 ; i < this->dt.size() ; i++){
            res[i] = (str[this->dt[i].first] - 'A' + this->dt[i].second) % 26 + 'A';
        }

        return res;
    }

    void apply(const Move& another){
        vector<pii> newDt;
        for(int i = 0;i < this->dt.size(); i++){
            newDt.push_back(this->dt[another.dt[i].first]); // 자리이동
            newDt[i].second = (newDt[i].second + another.dt[i].second) % 26;  // 알파벳 추가
        }
        this->dt = newDt;
    }
};

Move move_; // base Cm
string str;
int n , c;
ll k;

Move getLower(ll p){
    if(p == 0) return Move(n);
    if(p == 1) return move_;
    Move lower = getLower(p / 2);
    lower.apply(lower);
    if(p % 2 == 1){
        // 홀수
        lower.apply(move_);
    }
    
    return lower;
}

int main(){
    vector<pair<bool , pair<int , int>>> vec;
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> c >> k;
    
    cin >> str;
    move_ = Move(n);

    for(int i = 1; i <= c; i++){
        char x;
        int a , b;
        cin >> x >> a >> b;
        vec.push_back({(x == 'S' ? 1 : 0) , {a , b}});

        if(x == 'S'){
            move_.swap(a , b);
        }else{
            move_.add(a , b);
        }
    }

    Move ans = getLower(k / c);

    str = ans.apply(str);

    for(int i = 0;i < k % c; i++){
        if(vec[i].first == 1){ //swap
            swap(str[vec[i].second.first] , str[vec[i].second.second]);
        }else{ //add
            str[vec[i].second.first] -= 'A';
            str[vec[i].second.first] += vec[i].second.second;
            str[vec[i].second.first] %= 26;
            str[vec[i].second.first] += 'A';
        }
    }

    cout << str << '\n';
}