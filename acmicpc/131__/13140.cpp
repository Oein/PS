#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <climits>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<int> nums;

int main() {
    int sx;
    cin >> sx;
    
    // hello, world
    
    for(int h = 1;h <= 9;h++)
        for(int e = 0;e <= 9;e++) {
            if(e == h) continue;
            for(int l = 0;l <= 9;l++) {
                if(l == e || l == h) continue;
                for(int o = 0;o <= 9;o++) {
                    if(o == l || o == e || o == h) continue;
                    for(int w = 1;w <= 9;w++) {
                        if(w == o || w == e || w == l || w == h) continue;
                        for(int r = 0;r <= 9;r++) {
                            if(r == w || r == o || r == e || r == l || r == h) continue;
                            for(int d = 0;d <= 9;d++) {
                                if(d == r || d == w || d == o || d == e || d == l || d == h) continue;
                                int f = 10000 * h + e * 1000 + l * 100 + l * 10 + o;
                                int s = w * 10000 + o * 1000 + r * 100 + l * 10 + d;
                                if(f + s == sx) {
                                    cout << "  ";
                                    string fx = to_string(f);
                                    string s_ = to_string(s);
                                    int g = 5 - fx.size();
                                    while (g--) {
                                        cout << " ";
                                    }
                                    cout << fx << "\n+ ";
                                    g = 5 - s_.size();
                                    while (g--) {
                                        cout << " ";
                                    }
                                    cout << s_ << "\n-------\n ";
                                    g = 6 - to_string(sx).size();
                                    while (g--) {
                                        cout << " ";
                                    }
                                    cout << sx;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    cout << "No Answer";
}
