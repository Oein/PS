#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    vector<bool> arr;
    vector<int> znarr;
    vector<int> hnarr;
    vector<int> harr;
    vector<int> zarr;
    cin >> n;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        if(x % 2) arr.push_back(1);
        else arr.push_back(0);
        if(x % 2) harr.push_back(x);
        else zarr.push_back(x);
    }
    
    int ans = 0;
    sort(harr.begin(), harr.end());
    sort(zarr.begin(), zarr.end());
    int hxa = 0;
    int zxa = 0;
    // l to r
    for(int i = 0;i < n;i++) {
        if(arr[i]) {
            // 홀
            znarr.push_back(zarr.size() + hxa);
            hnarr.push_back(hxa);
            hxa++;
        } else {
            znarr.push_back(zxa);
            hnarr.push_back(harr.size() + zxa);
            zxa++;
        }
    }
    
    int bubbleSwapCount = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (znarr[j] > znarr[j + 1]) {
                swap(znarr[j], znarr[j + 1]);
                bubbleSwapCount++;
            }
    
    int ans2 = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (hnarr[j] > hnarr[j + 1]) {                swap(hnarr[j], hnarr[j + 1]);
                ans2++;
            }

    cout << min(bubbleSwapCount, ans2);
}
