#include <bits/stdc++.h>
using namespace std;
int score[2005];
int ansed[2005];
bool solved[2005][2005];
pair<int , int> anss[2005];

int n , t , p;

bool cmp(pair<int , int> a , pair<int , int> b){
    if(a.first == b.first){
        if(ansed[a.second] == ansed[b.second]){
            return a.second < b.second;
        }
        return ansed[a.second] > ansed[b.second];
    }
    return a.first > b.first;
}

int main(){
    cin >> n >> t >> p;
    fill(score , score + t + 1 , 0);
    for(int i = 1;i <= n;i++){
        anss[i].second = i;
        for(int j = 1;j <= t;j++){
            int x;
            cin >> x;
            solved[i][j] = x == 1 ? true : false;
            if(solved[i][j]){
                score[j]++;
                ansed[i]++;
            }
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= t;j++){
            if(solved[i][j] == true) anss[i].first += (n - score[j]);
        }
    }

    sort(anss + 1 , anss + n + 1 , cmp);

    for(int i = 1;i<= n;i++){
        if(anss[i].second == p){
            cout << anss[i].first << " " << i;
            return 0;
        }
    }
}