#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0;
    vector<int> vec;
    vector<int> cnt;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int vec_cnt; cin >> vec_cnt;
        cnt.push_back(vec_cnt);
    }
    for (int i = 0; i < N; i++) {
        int vec_num; cin >> vec_num;
        vec.push_back(vec_num);
    }
    sort(vec.begin(), vec.end()); sort(cnt.begin(), cnt.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += vec[i] * cnt[i];
    cout << sum;
    return 0;
}
