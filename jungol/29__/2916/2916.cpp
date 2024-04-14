#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <numbers>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int , int> pii;
typedef vector<int> vi;

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};

pii parant[100005]; // pair<부모 번호 , 색깔>
int check[100005];
int checkNum = 1;

int getTheSamePar(int a , int b) {
    while (1) {
        if(a != -1) {
            if(check[a] == checkNum) {
                checkNum++;
                return a;
            }
            check[a] = checkNum;
            a = parant[a].first;
        }

        if(b != -1) {
            if(check[b] == checkNum) {
                checkNum++;
                return b;
            }
            check[b] = checkNum;
            b = parant[b].first;
        }
    }

    return 0;
}

void print(int a , int b , int c) {
    int par = getTheSamePar(a , b);
    while(a != par) {
        parant[a].second = c;
        a = parant[a].first;
    }

    while(b != par) {
        parant[b].second = c;
        b = parant[b].first;
    }
}

void move(int a , int b) {
    parant[a].first = b;
}

void count(int a , int b) {
    int par = getTheSamePar(a , b);
    set<int> c;
    int cc = 0;
    while (a != par) {
        if(c.find(parant[a].second) == c.end()) {
            c.insert(parant[a].second);
            cc++;
        }
        a = parant[a].first;
    }
    while (b != par) {
        if(c.find(parant[b].second) == c.end()) {
            c.insert(parant[b].second);
            cc++;
        }
        b = parant[b].first;
    }

    cout << cc << "\n";
}

int main(){
    cin.tie(0); cout.tie(0);
    int n , k;
    cin >> n >> k;
    parant[0].first = -1; // 조상이 없을때
    for(int i = 0;i < k;i++) {
        int r;
        cin >> r;
        int a , b , c;
        if(r == 1) {
            cin >> a >> b >> c;
            print(a , b , c);
        }
        if(r == 2) {
            cin >> a >> b;
            move(a , b);
        }
        if(r == 3) {
            cin >> a >> b;
            count(a , b);
        }
    }
}