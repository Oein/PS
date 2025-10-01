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
long long cnt[1005] = {0,};

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    long long sum = 0;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        sum += num;
        cnt[sum % m]++;
    }
    long long ans = 0;
    for(int i = 0;i <= 1000;i++)
        ans += cnt[i] * (cnt[i] - 1) / 2;
    cout << cnt[0] + ans;
}
