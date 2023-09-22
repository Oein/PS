#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, k, cnt, sum;
vector<int> v;
int arr[100001];
int arr2[100001];
 
int big(int num) {
    for (int i = 0; i < v.size(); i++) {
        if (num == v[i]) {
            v[i] = 0;
            return 1;
        }
    }
    return 0;
}
 
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    sort(arr2, arr2 + n);
 
    int c = 0;
    for (int i = n - 1; c < k; i--) {
        v.push_back(arr2[i]);
        c++;
    }
 
    for (int i = 0; i < n; i++) {
        if (big(arr[i]) && cnt < k) {
            sum += arr[i] - cnt;
            cnt++;
        }
    }
 
    cout << sum;
}
