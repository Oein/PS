#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include <limits>
#include <string>
#include <cmath>
#include <stack>
#include <climits>
#include <queue>
#include <numeric>

using namespace std;
using ull = unsigned long long;
using ll = long long;

int main() {
    ll a,b,v;
    cin >> a >> b >> v;
    ll up = a - b;
    ll mud = (v - a) / up + ((v - a) % up ? 1 : 0);
    ll uped = up * mud;
    
    cout << mud + 1;
}
