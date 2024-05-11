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

pi_i arr[201];

bool cmp(pi_i a, pi_i b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main(){
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr , arr + n , cmp);

    int ans = 1;

    int maxDegree = arr[0].second;
  
    for (int i = 1; i < n; i++) {
        if (maxDegree < arr[i].first) {
            maxDegree = arr[i].second;
            ans++;
        }
    }

    cout << ans;
}