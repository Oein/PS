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
    int s , e;
    cin >> s >> e;
    sort(a + s , a + e + 1);
    for(int i = 0;i < n;i++)cout << a[i] << " ";
    cout << "\n";
    sort(a , a + n);
    for(int i = 0;i < n;i++)cout << a[i] << " ";
}