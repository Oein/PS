#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

string xtos(int y) {
    char ch[] = "ABCDEFGHIJKL";
    string ans = "12";
    ans[0] = ch[y % 12];
    ans[1] = (y % 10) + '0';
    return ans;
}

int main() {
    int year;
    cin >> year;
    year += 56;
    year %= 60;
    cout << xtos(year);
}
