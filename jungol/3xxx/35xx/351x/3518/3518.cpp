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
typedef pair<pair<int , int> , pair<int , int>> ppi_i__pi_i;
typedef pair<long long , long long> pll_ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<int , int> mii;
typedef map<string , int> ms_i;
typedef map<string , string> ms_s;
typedef set<int> si;
typedef set<string> ss;
typedef set<long long> sll;

int a[1005];
int n;

void quick_sort(int low , int high){
    if(low >= high) return;
    int pivot = a[high];
    int left = low;
    int right = low;
    while(right <= high){
        if(a[right] < pivot) {
            swap(a[left] , a[right]);
            left++;
        }
        right++;
    }

    swap(a[left] , a[right - 1]);

    for(int i = 0;i < n;i++) cout << a[i] << " ";
    cout << "\n";

    quick_sort(low , left - 1);
    quick_sort(left + 1 , high);
}

int main() {
	cin.tie(0); cout.tie(0);
    cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
    quick_sort(0 , n - 1);
}