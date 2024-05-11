#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int , int> pi_i;

int n;
int a[100005];

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++)cin >> a[i];

    // 이게 함수 버전
    sort(a , a + n , greater<int>());

    // reverse 버전
    // sort(a,a+n);
    // reverse(a,a+n);
    for(int i = 0;i < n;i++)cout << a[i] << " ";
}