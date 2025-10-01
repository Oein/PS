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
int arr[500005] , finalCopyArr[500005];

void mergeSort(int* arr , int st , int ed){
    if(st >= ed) return;
    
    int mid = (st + ed) / 2;
    mergeSort(arr , st , mid);
    mergeSort(arr, mid + 1 , ed);


    int i = st, j = mid + 1, k = st;
    while (i <= mid && j <= ed) {
        if (arr[i] < arr[j]) finalCopyArr[k++] = arr[i++];
        else {
            finalCopyArr[k++] = arr[j++];
        }
    }
 
    while (i <= mid) finalCopyArr[k++] = arr[i++];
    while (j <= ed) finalCopyArr[k++] = arr[j++];

    for(int i = st;i <= ed;i++){
        arr[i] = finalCopyArr[i];
    }

    for(int i = 0;i < n;i++) cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    mergeSort(arr , 0 , n - 1);
}