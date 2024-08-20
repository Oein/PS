#include <iostream>
#include <algorithm>
using namespace std;
using int32 = int32_t;
using int64 = int64_t;
int64 X, Y, Z;
bool test(int64 win) {
        auto newZ = (100 * (Y + win) / (X + win));
        return Z < newZ;
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> X >> Y;
        Z = (100 * Y / X);
        //! simple check.
        if(99 <= Z) {
                cout << -1 << '\n';
                return 0;
        }
        //! search, first true.
        int64 srt, end, mid, ret = -1;
        srt = 0;
        end = X+1;
        while (srt < end) {
                mid = (srt + end) / 2;
                if (test(mid)) {
                        ret = mid;
                        end = mid;
                }
                else srt = mid + 1;
        }
        cout << ret << '\n';
}