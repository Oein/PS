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

bool arr[105][105];

char tojin(int x) {
    if(x < 10) return x + '0';
    return x - 10 + 'A';
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    int num, jin;
    cin >> num >> jin;
    stack<char> s;
    while (num) {
        s.push(tojin(num % jin));
        num /= jin;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
