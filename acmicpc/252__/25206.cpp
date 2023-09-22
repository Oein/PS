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
    double sum = 0;
    double csum = 0;
    int cnt = 0;
    for(int i = 0;i < 20;i++) {
        string name;
        double score;
        string scn;
        cin >> name >> score >> scn;
        if(scn == "P") continue;
        csum += score;
        double sc = 0;
        if(scn == "A+") sc = 4.5;
        if(scn == "A0") sc = 4;
        if(scn == "B+") sc = 3.5;
        if(scn == "B0") sc = 3;
        if(scn == "C+") sc = 2.5;
        if(scn == "C0") sc = 2;
        if(scn == "D+") sc = 1.5;
        if(scn == "D0") sc = 1;
        sum += sc * score;
        cnt++;
    }
    cout << sum / csum;
}
