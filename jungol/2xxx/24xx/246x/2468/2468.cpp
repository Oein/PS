#include <iostream>

using namespace std;

using ull=unsigned long long;

ull n;
ull low = 0;
ull high = 0;
ull mask = 3;
ull oneCnt = 0;
ull one = 1;

int main() {
    cin >> n;
    
    while (1) {
        if(low && high) break;
        if(one > n) break;
        
        if((n & mask) == (one << 1)) {
            // get low
            low = n ^ mask;
            low = low / one * one;
            ull newn = one >> 1;
            ull cnt = oneCnt;
            while (newn && cnt--) {
                low += newn;
                newn >>= 1;
            }
        }
        
        if((n & mask) == (one)) {
            // get high
            high = n ^ mask;
            high = high / one * one;
            ull newn = 1;
            ull cnt = oneCnt;
            
            while (newn && cnt--) {
                high += newn;
                newn <<= 1;
            }
        }
        
        if(n & one) oneCnt++;
        
        one <<= 1;
        mask <<= 1;
    }
    
    cout << low << " " << high;
}

// Upper
// 1010101
// 1010110

// Lower
// 1010101
// 1010011

// 100101011 (299)
// 100100111 (295, D)
// 100011011 (283, D)
// 100010111 (279, D)

// 101011
// 100111 (D)
// 101101 (U)


// 110011
// 101110 (D)

// 11011111100
// 11100011111 (U)

// 101011
// 100100
