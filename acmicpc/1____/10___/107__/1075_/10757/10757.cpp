#include <bits/stdc++.h>
using namespace std;
string Add(string &s1, string &s2) {
    string result(max(s1.size(), s2.size()), '0');
    bool carry = false;
    for (int i = 0; i < result.size(); i++) {
        int temp = carry;
        carry = false;
        if (i < s1.size()) temp += s1[s1.size() - i - 1] - '0';
        if (i < s2.size()) temp += s2[s2.size() - i - 1] - '0';
        if (temp >= 10) {
            carry = true; temp -= 10;
        }
        result[result.size() - i - 1] = temp + '0';
    }
    if (carry) result.insert(result.begin(), '1');
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string A = "", B = "";
    cin >> A >> B;
    string result = Add(A, B);
    cout << result << "\n"; return 0;
}
