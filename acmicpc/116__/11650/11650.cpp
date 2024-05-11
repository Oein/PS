#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
    if(b.first > a.first)
        return true;
    else if(b.first == a.first){
        if(b.second > a.second)
            return true;
        else
            return false;
    }
    else
        return false;
}
 
int main(int argc, const char * argv[]) {
    int N;
    cin >> N; //좌표 개수 입력 받기.
    vector <pair<int, int>> v(N);
    //N사이즈의 vector 선언.
    //pair 클래스 타입.
    
    for(int i = 0; i < N; i++){
        cin >> v[i].first >> v[i].second;
    } //N 만큼 좌표 입력 받기 (x -> first, y -> second)
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < N; i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
    
    return 0;
}
