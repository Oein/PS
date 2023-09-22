#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    int answer = 0;
    cin >> N;
    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        v.emplace_back(X, Y);
    }

    sort(v.begin(), v.end(), [](auto a, auto b) {
        if (a.first < b.first) return true;
        else return false;
        });

    //왼쪽 넓이 구하기
    int left_locate = v[0].first;
    int left_MAX = v[0].second;
    
    for (auto& p : v) {
        if (left_MAX <= p.second) {
            answer += (p.first - left_locate) * left_MAX;
            left_MAX = p.second;
            left_locate = p.first;
        }
    }

    //오른쪽 넓이 구하기
    int right_locate = v.back().first;
    int right_MAX = v.back().second;
    
    for (int i = v.size() - 1; i > -1; i--) {
        if (right_MAX < v[i].second) {
            answer += (right_locate - v[i].first) * right_MAX;
            right_MAX = v[i].second;
            right_locate = v[i].first;
        }
    }
    cout << answer + left_MAX << endl;

    return 0;
}