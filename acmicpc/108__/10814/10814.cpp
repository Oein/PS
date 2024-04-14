#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <stack>
#include <cstring>

using namespace std;

typedef long long ll;
typedef unsigned long ull;
typedef pair<int, int> pii;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;
using t = pair<pair<int , int>, string>;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    vector<t> v;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        int x;
        string y;
        cin >> x >> y;
        v.push_back({{x, i}, y});
    }
    sort(v.begin(), v.end(), [](const t a, const t b) {
        return a.first.first == b.first.first ? a.first.second < b.first.second : a.first.first < b.first.first;
    });
    for(auto x : v) {
        cout << x.first.first << " " << x.second << "\n";
    }
}
