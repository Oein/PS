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

int main()
{
    cin.tie(0);
    cout.tie(0);
    int x;
    while (true) {
        cin >> x;
        if(x == -1) break;
        vector<int> yak;
        yak.push_back(1);
        int hap = 1;
        for(int i = 2;i * i <= x;i++) {
            if(x % i) continue;
            yak.push_back(i);
            yak.push_back(x / i);
            hap += i + x / i;
        }
        if(hap != x) cout << x << " is NOT perfect.\n";
        else {
            sort(yak.begin(), yak.end());
            cout << x << " = ";
            for(int i = 0;i < yak.size();i++) {
                cout << yak[i];
                if(i + 1 != yak.size()) cout << " + ";
            }
            cout << "\n";
        }
    }
}
