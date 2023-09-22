#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool debug = false;
bool print_end_msg = false || debug;
bool print_in_l74 = false || debug;
bool print_flowers = false || debug;

bool sort_func(pair<int, int>  a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    int n;

    vector<pair<int, int> > v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;

        v.push_back({ s1 * 100 + s2, e1 * 100 + e2 });
    }

    sort(v.begin(), v.end(), sort_func);

    int ed = 301;

    int result = 0;

    for (int i = 0; i < n;) {
        if (v[i].first > ed) { // 닫지 못하면

            cout << "0";
            return 0;
        }

        int bigest = -1;

        for (; i < n && v[i].first <= ed; i++) {
            bigest = max(bigest, v[i].second);
        }


        ed = bigest;
        result++;

        if (ed > 1130) break;
    }

    if (ed > 1130) cout << result;
    else cout << "0\n";
    

    return 0;
}