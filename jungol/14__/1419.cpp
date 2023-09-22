#include <bits/stdc++.h>
using namespace std;
unsigned int orig = 0;

int main() {
     cin >> orig;
     vector<int> nums;
     while(orig) {
        nums.push_back(orig % (2 << 7));
        orig >>= 8;
     }
     unsigned int ans = 0;
     int shif = 0;
     for(int i = nums.size() - 1;i >= 0;i--) {
        // cout << i << " / " << nums[i] << "\n";
        unsigned int x = nums[i];
        ans += (x << shif);
        shif+=8;
     }
     cout << ans;
}
