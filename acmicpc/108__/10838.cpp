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

int n , k;

pii parent[100001]; // pair<부모 번호 , color>
int check[100001];
int checkNumNow = 1;

int getSameParent(int a , int b){ // union find 같은건가?
    while(1){
        if(a != -1){
            if(check[a] == checkNumNow) {
                checkNumNow++;
                return a;
            }
            check[a] = checkNumNow;
            a = parent[a].first;
        }
        if(b != -1){
            if(check[b] == checkNumNow) {
                checkNumNow++;
                return b;
            }
            check[b] = checkNumNow;
            b = parent[b].first;
        }
    }
    return 0;
}

void paint(int a , int b , int c){
    int sameParent = getSameParent(a , b);
    while (a != sameParent) {
        parent[a].second = c;
        a = parent[a].first;
    }
    while (b != sameParent) {
        parent[b].second = c;
        b = parent[b].first;
    }
}

void move(int a , int b){
    parent[a].first = b;
}

void count(int a , int b){
    int sameParent = getSameParent(a , b);
    set<int> used;
    int colorCount = 0;
    while (a != sameParent) {
        if(used.find(parent[a].second) == used.end()){
            used.insert(parent[a].second);
            colorCount++;
        }
        a = parent[a].first;
    }
    while (b != sameParent) {
        if(used.find(parent[b].second) == used.end()){
            used.insert(parent[b].second);
            colorCount++;
        }
        b = parent[b].first;
    }
    cout << colorCount << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    parent[0].first = -1;
    for(int i = 0;i < k;i++){
        int r;
        cin >> r;
        if(r == 1){
            int a , b , c;
            cin >> a >> b >> c;
            paint(a , b , c);
        }
        else if(r == 2){
            int a , b;
            cin >> a >> b;
            move(a , b);
        }
        else{
            int a , b;
            cin >> a >> b;
            count(a , b);
        }
    }
}